#include "header.h"
/*
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
*/
void    rra(t_box    *stacks)
{
    int len;
    t_stack *tmp;
    t_stack *boat;
    len = ft_list_len(stacks->stack_a);
    if (len > 1)
    {
        boat = stacks->stack_a;
        while(boat->next->next != NULL)
            boat = boat->next;
        tmp = boat->next;
        boat->next = NULL;
        tmp->next = stacks->stack_a;
        stacks->stack_a = tmp;
    }
}

/*
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
*/
void    rrb(t_box    *stacks)
{
    int len;
    t_stack *tmp;
    t_stack *boat;
    len = ft_list_len(stacks->stack_b);
    if (len > 1)
    {
        boat = stacks->stack_b;
        while(boat->next->next != NULL)
            boat = boat->next;
        tmp = boat->next;
        boat->next = NULL;
        tmp->next = stacks->stack_b;
        stacks->stack_b = tmp;
    }
}

/*
rra and rrb at the same time.
*/
void    rrr(t_box    *stacks)
{
    rra(stacks);
    rrb(stacks);
}