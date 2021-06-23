#include "header.h"

void    game_start(int  *int_cast, int argc)
{
    t_box   *stacks;

    stacks = initialise_t_box(stacks);
    initialise_stack_a(stacks, int_cast, argc);
    initialise_stack_b(stacks);
    /**/
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
        int_cast = initial_error_management(argc, argv, int_cast);
        if (is_sorted(int_cast, argc) == 1)
        {
            //system("leaks push_swap");
            return (1);
        }
        //game_start(int_cast, argc);
    }
    //system("leaks push_swap");
}