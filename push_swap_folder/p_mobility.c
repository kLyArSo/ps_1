#include "header.h"
/*
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
*/
void    pa(t_box    *stacks)
{
    int len;
    t_stack *ptr;

    ptr = stacks->stack_b;
    len = ft_list_len(ptr);
    if (len > 0)//stack b not empty
    {
        if (len == 1)
            stacks->stack_b = NULL;
        else
            stacks->stack_b = stacks->stack_b->next;
        ptr->next =  stacks->stack_a;
        stacks->stack_a = ptr;
        write(1, "pa\n", 3);
    }
}

/*
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
*/

void    pb(t_box    *stacks)
{
    int len;
    t_stack *ptr;

    ptr = stacks->stack_a;
    len = ft_list_len(ptr);
    if (len > 0)//stack a not empty
    {
        if (len == 1)
            stacks->stack_a = NULL;
        else
            stacks->stack_a = stacks->stack_a->next;
        ptr->next = stacks->stack_b;
        stacks->stack_b = ptr;
        write(1, "pb\n", 3);
    }
}