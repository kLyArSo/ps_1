#include "header.h"


int     check_command_validity(char *str)
{
    if (strcmp(str, "sa") != 0 && strcmp(str, "sb") != 0&& strcmp(str, "ss") != 0
     && strcmp(str, "ra") != 0 && strcmp(str, "rb") != 0 && strcmp(str, "rr") != 0 
   && strcmp(str, "rra") != 0 && strcmp(str, "rrb") != 0 && strcmp(str, "rrr") != 0
     && strcmp(str, "pa") != 0 && strcmp(str, "pb") != 0)
        return (0);
    return (1);
}


void    apply_instruction(t_box   *stacks, t_instruction   *instr)
{
    char *str;
    while(instr != NULL)
    {   
        str = instr->instruction;
        if (strcmp(str, "pa") == 0)
            pa(stacks);
        else if (strcmp(str, "pb") == 0)
            pb(stacks);
        else if (strcmp(str, "sa") == 0)
            sa(stacks);
        else if (strcmp(str, "sb") == 0)
            sb(stacks);
        else if (strcmp(str, "ss") == 0)
            ss(stacks);
        else if (strcmp(str, "ra") == 0)
            ra(stacks);
        else if (strcmp(str, "rb") == 0)
            rb(stacks);
        else if (strcmp(str, "rr") == 0)
            rr(stacks);
        else if (strcmp(str, "rra") == 0)
            rra(stacks);
        else if (strcmp(str, "rrb") == 0)
            rrb(stacks);
        else if (strcmp(str, "rrr") == 0)
            rrr(stacks);
        instr = instr->next;
    }
}

t_instruction   *get_instructions()
{
    char *cmd;
    int i;
    int k;
    t_instruction   *instr;
    t_instruction   *ptr;

    k = 0;
    instr = NULL;

    while (1)
    {
        if (get_next_line(1, &cmd) == 1)
        {
            if (check_command_validity(cmd) == 0)
            {
                printf("Error\n");
                exit(0);
            }
            if (k == 0)
            {
                instr = malloc(sizeof(t_instruction));
                ptr = instr;
                ptr->instruction = cmd;
                ptr->next = NULL;
                k = 1;
            }
            else if (k == 1)
            {
                ptr->next = malloc(sizeof(t_instruction));
                ptr = ptr->next;
                ptr->instruction = cmd;
                ptr->next = NULL;
            }
        }
        else
        {
            free(cmd);
            break ;
        }
    }
    return (instr);
}

int     *list_to_int_buff(t_box   *stacks)
{
    int i;
    int *ret;
    t_stack *ptr;
    i = ft_list_len(stacks->stack_a);
    ret = malloc(i * sizeof(int));
    i = 0;
    ptr = stacks->stack_a;
    while(ptr != NULL)
    {
        ret[i] = ptr->element;
        i++;
        ptr = ptr->next;
    }
    return (ret);
}
void    check_if_sorted(int  *int_cast, int  *post_instructions, int argc)
{
    int     *algo_sorted;

    algo_sorted = quick_sort(int_cast, argc - 1);
    //algo_sorted and int cast point to same area in memory
    if (int_buff_cmp_1(algo_sorted, post_instructions, argc - 1) == 0)
        printf("KO\n");
    else
        printf("OK\n");

}
void    check_start(int  *int_cast, int argc, t_instruction   *instr)
{
    t_box   *stacks;
    int     *post_instructions;
    stacks = initialise_t_box(stacks);
    initialise_stack_a(stacks, int_cast, argc);
    initialise_stack_b(stacks);
    apply_instruction(stacks, instr);
    if (ft_list_len(stacks->stack_b) != 0)
    {
        int_cast = free_int_buffer(int_cast);
        printf("KO\n");
    }
    else
    {
        post_instructions = list_to_int_buff(stacks); //convert it back into int buffer
        check_if_sorted(int_cast, post_instructions, argc);//check that stack a is sorted and that stacck n is empty
    }
    stacks->stack_a = free_stack(stacks->stack_a);
    stacks->stack_b = free_stack(stacks->stack_b);
    free(stacks);
    stacks = NULL;
}

void    free_inst_content(t_instruction   *instr)
{
    while(instr != NULL)
    {
        free(instr->instruction);
        instr = instr->next;
    }
}
void    free_inst_nodes(t_instruction   *instr)
{
    t_instruction   *tmp;

    while(instr != NULL)
    {
        tmp = instr;
        instr = instr->next;
        free(tmp);
    }

}
int     main(int argc, char **argv)
{
    int  *int_cast;
    t_instruction   *instr;
    int len;
    if (argc > 1)
    {
        int_cast = initial_error_management(argc, argv, int_cast);
        instr = get_instructions();
        len = ft_list_len_inst(instr);
        if (len != 0)
            check_start(int_cast, argc, instr);
        free_inst_content(instr);
        free_inst_nodes(instr);
    }
    system("leaks checker | grep bytes");
}