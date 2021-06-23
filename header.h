#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct  s_stack
{
    int             element;
    struct s_stack  *next;
    
}               t_stack;

typedef struct  s_box
{
    t_stack *stack_a;
    t_stack *stack_b;
}               t_box;

int     ft_strlen(char *str);
int		ft_atoi(char *src, char *c);
char	*my_calloc(int	length);
char	*ft_substr(char	*str, int	start, int	end);
int     is_white_space(char	c);
char	*trim_spaces(char	*input);
int     is_empty_array(char **argv);
char    **fetch_array(int argc, char **argv);
void    print_buff(char **buffer);
int     dig_check(char  *str);
int     sign_check(char  *str);
int     arg_validity(char   **buffer);
int     main(int argc, char **argv);
int     *convert_to_int(int argc, char **buffer, char *c);
void    printf_int_array(int argc, int  *int_cast);
char    **free_char_buffer(char   **buffer);
int     check_for_int_dup(int c, int *int_cast, int i, int argc);
int     check_for_dups(int argc, int  *int_cast);
int     *free_int_buffer(int  *int_cast);
int     *initial_error_management(int argc, char **argv, int  *int_cast);
int		ft_list_len(t_stack *stack);
void    sa(t_box    *stacks);
void    sb(t_box    *stacks);
void    ss(t_box    *stacks);

void    pa(t_box    *stacks);
void    pb(t_box    *stacks);

void    ra(t_box    *stacks);
void    rb(t_box    *stacks);
void    rr(t_box    *stacks);

void    rra(t_box    *stacks);
void    rrb(t_box    *stacks);
void    rrr(t_box    *stacks);

t_box   *initialise_t_box(t_box   *stacks);
void    initialise_stack_a(t_box   *stacks, int  *int_cast, int argc);
void    initialise_stack_b(t_box   *stacks);
void    print_stack(t_stack *stack);
t_stack *free_stack(t_stack *stack);
void    test_mob(t_box *stacks);
int    is_sorted(int  *int_cast, int argc);
int     *int_buff_dup(int  *buff, int n);

