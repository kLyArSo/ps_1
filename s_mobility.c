#include "header.h"
/*
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
*/
void    sa(t_box    *stacks)
{
    int len;
    int tmp;
    t_stack *ptr;

    ptr = stacks->stack_a;
    len = ft_list_len(ptr);
    if (len > 1)
    {
        tmp = ptr->element;
        ptr->element = ptr->next->element;
        ptr->next->element = tmp;
    }
}
/*
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
*/
void    sb(t_box    *stacks)
{
    int len;
    int tmp;
    t_stack *ptr;

    ptr = stacks->stack_b;
    len = ft_list_len(ptr);
    if (len > 1)
    {
        tmp = ptr->element;
        ptr->element = ptr->next->element;
        ptr->next->element = tmp;
    }
}
/*
ss : sa and sb at the same time.
*/
void    ss(t_box    *stacks)
{
    sa(stacks);
    sb(stacks);
}