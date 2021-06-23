#include "header.h"

t_box   *initialise_t_box(t_box   *stacks)
{
    stacks = malloc(sizeof(t_box));
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
    return (stacks);
}

void    initialise_stack_a(t_box   *stacks, int  *int_cast, int argc)
{
    int i;
    i = 0;
    t_stack *tmp;

    stacks->stack_a = malloc(sizeof(t_stack));
    tmp = stacks->stack_a;
    while (i <= argc - 3)
    {
        tmp->element = int_cast[i];
        i++;
        tmp->next = malloc(sizeof(t_stack));
        tmp = tmp->next;
    }
    tmp->element = int_cast[i];
    tmp->next = NULL;
    int_cast = free_int_buffer(int_cast);
}

void    initialise_stack_b(t_box   *stacks)
{
    stacks->stack_b = NULL;
}

void    print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->element);
        stack = stack->next;
    }
}

t_stack *free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack != NULL)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
    return (NULL);
}

void    test_mob(t_box *stacks)
{
    /*------------------------------------------------------------*/
    printf("000000000000000000000000000000000000000\n");
    print_stack(stacks->stack_a);
    printf("112121321321321321321132131313213213213213132\n");
    print_stack(stacks->stack_b);
    printf("000000000000000000000000000000000000000\n");
    printf("----------------------------------\n");

    rra(stacks);
    rra(stacks);
    pb(stacks);
    rr(stacks);
    pa(stacks);
    ra(stacks);
    printf("stack_a\n");
    print_stack(stacks->stack_a);
    printf("stack_b\n");
    print_stack(stacks->stack_b);

}
