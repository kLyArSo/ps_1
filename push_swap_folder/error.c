#include "header.h"

void    array_err()
{

        printf("Error\n");
        system("leaks push_swap | grep  bytes");
        exit(0);
}

void    validity_err(char **buffer)
{

        printf("Error\n");
        buffer = free_char_buffer(buffer);
        system("leaks push_swap | grep  bytes");
        exit(0);
}

void    atoi_err(char **buffer, int  *int_cast)
{

        printf("Error\n");
        buffer = free_char_buffer(buffer);
        int_cast = free_int_buffer(int_cast);
        system("leaks push_swap | grep  bytes");
        exit(0);
}

void    dup_err(char **buffer, int  *int_cast)
{

        printf("Error\n");
        buffer = free_char_buffer(buffer);
        int_cast = free_int_buffer(int_cast);
        system("leaks push_swap | grep  bytes");
        exit(0);
}

int  *initial_error_management(int argc, char **argv, int  *int_cast)
{
    char **buffer;
    char c;

    if (is_empty_array(argv) == -1)
        array_err();
    buffer = fetch_array(argc, argv);
    if (arg_validity(buffer) == -1)
        validity_err(buffer);
    int_cast = convert_to_int(argc, buffer, &c);
    if (c == 'a')
        atoi_err(buffer, int_cast);
    if (check_for_dups(argc, int_cast) == 1)
        dup_err(buffer, int_cast);
    buffer = free_char_buffer(buffer);
    return (int_cast);
}  
