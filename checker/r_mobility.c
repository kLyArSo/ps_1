#include "header.h"
/*
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
*/
void    ra(t_box    *stacks)
{
    int len;
    t_stack *tmp;
    t_stack *boat;
    len = ft_list_len(stacks->stack_a);
    if (len > 1)
    {
        tmp = stacks->stack_a;
        boat = tmp;
        stacks->stack_a = stacks->stack_a->next;
        while (boat->next != NULL)
            boat = boat->next;
        boat->next = tmp;
        boat = boat->next;
        boat->next = NULL;
    }
}

/*
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
*/
void    rb(t_box    *stacks)
{
    int len;
    t_stack *tmp;
    t_stack *boat;
    len = ft_list_len(stacks->stack_b);
    if (len > 1)
    {
        tmp = stacks->stack_b;
        boat = tmp;
        stacks->stack_b = stacks->stack_b->next;
        while (boat->next != NULL)
            boat = boat->next;
        boat->next = tmp;
        boat = boat->next;
        boat->next = NULL;
    }
}

/*
rr : ra and rb at the same time.
*/
void    rr(t_box    *stacks)
{
    ra(stacks);
    rb(stacks);
}