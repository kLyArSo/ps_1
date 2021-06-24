#include "header.h"

int     fetch_min(t_box   *stacks)
{
    int min;
    t_stack *tmp;
    
    tmp = stacks->stack_a;
    min = tmp->element;
    while (tmp != NULL)
    {
        if (min > tmp->element)
            min = tmp->element;
        tmp = tmp->next;
    }
    return (min);
}

int     fetch_max(t_box   *stacks)
{
    int max;
    t_stack *tmp;
    
    tmp = stacks->stack_a;
    max = tmp->element;
    while (tmp != NULL)
    {
        if (max < tmp->element)
            max = tmp->element;
        tmp = tmp->next;
    }
    return (max);
}

int     fetch_index(t_box   *stacks, int x)
{
    int i;
    t_stack *tmp;
    
    tmp = stacks->stack_a;
    i = 0;
    while (tmp != NULL)
    {
        if (tmp->element == x)
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (-1);
}

void    deux_args(t_box   *stacks)
{
    int head;
    int tail;

    head = stacks->stack_a->element;
    tail = stacks->stack_a->next->element;
    if (head >= tail)
    {
        printf("sa\n");
        sa(stacks);
    }
}

int     fetch_middle(int x, int y)
{
    int sum;

    sum = x + y;
    if (sum == 3)
        return (0);
    if (sum == 2)
        return (1);
    if (sum == 1)
        return (2);
    return (-1);
}

void    zero_two_one(t_box   *stacks)
{
    rra(stacks);
    sa(stacks);
}

void    one_zero_two(t_box   *stacks)
{
    sa(stacks);
}

void    one_two_zero(t_box   *stacks)
{
    rra(stacks);
}

void    two_zero_one(t_box   *stacks)
{
    ra(stacks);
}

void    two_one_zero(t_box   *stacks)
{
    sa(stacks);
    rra(stacks);
}

void    trois_args(t_box   *stacks)
{
    int zero;
    int one;
    int two;

    //printf("(min, max) = (%d,%d)\n", fetch_min(stacks), fetch_max(stacks));
    zero = fetch_index(stacks, fetch_min(stacks));
    //printf("zero = %d\n",zero);
    two = fetch_index(stacks, fetch_max(stacks));
    one = fetch_middle(zero, two);
    if (zero == 0 && one == 2 && two == 1)
        zero_two_one(stacks);
    else if (zero == 1 && one == 0 && two == 2)
        one_zero_two(stacks);
    else if (zero == 2 && one == 0 && two == 1)
        two_zero_one(stacks);
    else if (zero == 1 && one == 2 && two == 0)
        one_two_zero(stacks);
    else if (zero == 2 && one == 1 && two == 0)
        two_one_zero(stacks);
}

void    quatre_args(t_box   *stacks)
{
    int i;

    i = fetch_index(stacks, fetch_min(stacks));
    if (i == 0)
        pb(stacks);
    else if (i == 1)
    {
        ra(stacks);
        pb(stacks);
    }
    else if (i == 2)
    {
        rra(stacks);
        rra(stacks);
        pb(stacks);
    }
    else if (i == 3)
    {
        rra(stacks);
        pb(stacks);
    }
    trois_args(stacks);
    pa(stacks);
}

void    cinq_args(t_box   *stacks)
{
    int i;

    i = fetch_index(stacks, fetch_min(stacks));
    if (i == 0)
        pb(stacks);
    else if (i == 1)
    {
        ra(stacks);
        pb(stacks);
    }
    else if (i == 2)
    {
        ra(stacks);
        ra(stacks);
        pb(stacks);
    }
    else if (i == 3)
    {
        rra(stacks);
        rra(stacks);
        pb(stacks);
    }
    else if (i == 4)
    {
        rra(stacks);
        pb(stacks);
    }
    quatre_args(stacks);
    pa(stacks);
}

void    push_swap(t_box   *stacks)
{
    int     nb;

    nb = ft_list_len(stacks->stack_a);
    if (nb == 2)
        deux_args(stacks);
    else if (nb == 3)
        trois_args(stacks);
    else if (nb == 4)
        quatre_args(stacks);
    else if (nb == 5)
        cinq_args(stacks);
}

void    game_start(int  *int_cast, int argc)
{
    t_box   *stacks;

    stacks = initialise_t_box(stacks);
    initialise_stack_a(stacks, int_cast, argc);
    initialise_stack_b(stacks);
    push_swap(stacks);
    //printf("min = %d\n", fetch_min(stacks));
    //printf("max = %d\n", fetch_max(stacks));
    //printf("min_pos = %d\n", fetch_index(stacks, fetch_min(stacks)));
    //printf("max_pos = %d\n", fetch_index(stacks, fetch_max(stacks)));
    stacks->stack_a = free_stack(stacks->stack_a);
    stacks->stack_b = free_stack(stacks->stack_b);
    free(stacks);
    stacks = NULL;
}

int     main(int argc, char **argv)
{
    int  *int_cast;

    if (argc > 1)
    {
        int_cast = initial_error_management(argc, argv, int_cast);// int_cast is allocated
        if (is_sorted(int_cast, argc) == 1)
        {
            printf("ALREDY SORTED\n");
            system("leaks push_swap | grep  bytes");
            return (1);
        }
        game_start(int_cast, argc);
    }
    //system("leaks push_swap | grep  bytes");
}