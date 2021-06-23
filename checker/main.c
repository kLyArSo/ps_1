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
        cmd = my_calloc(5 * sizeof(char));
        if (get_next_line(1 ,&cmd) == 1)
        {
            if (check_command_validity(cmd) == 0)
            {
                printf("KO : UNEXISTANT_INSTRUCTION\n");
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
            break ;
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
void    check_if_sorted(int  *post_instructions, int argc)
{
    int     *algo_sorted;

    algo_sorted = quick_sort(algo_sorted, argc - 1);
    if (int_buff_cmp(algo_sorted, post_instructions, argc - 1) == 0)
        printf("KO");
    else
        printf("OK");

}
void    check_start(int  *int_cast, int argc, t_instruction   *instr)
{
    t_box   *stacks;
    int     *post_instructions;
    stacks = initialise_t_box(stacks);
    initialise_stack_a(stacks, int_cast, argc);
    initialise_stack_b(stacks);

    apply_instruction(stacks, instr);//apply instructions to list
    if (ft_list_len(stacks->stack_b) != 0)
        printf("KO\n");
    else
    {
        post_instructions = list_to_int_buff(stacks); //convert it back into int buffer
        check_if_sorted(post_instructions, argc);//check that stack a is sorted and that stacck n is empty
    }
    stacks->stack_a = free_stack(stacks->stack_a);
    stacks->stack_b = free_stack(stacks->stack_b);
    free(stacks);
    stacks = NULL;
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
        printf("list length = %d\n", len);
        if (len != 0)
            check_start(int_cast, argc, instr);
    }
    //system("leaks push_swap");
}