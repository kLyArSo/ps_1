#include "header.h"

char   **free_char_buffer(char   **buffer)
{
    int i;

    i = 0;
    while(buffer[i] != NULL)
    {
        free(buffer[i]);
        i++;
    }
    free(buffer);
    return (NULL);
}

int     *free_int_buffer(int  *int_cast)
{
    free(int_cast);
    return (NULL);
}

void    printf_int_array(int argc, int  *int_cast)
{
    int i;

    i = 0;
    while (i < argc - 1)
    {
        printf("num = %d\n", int_cast[i]);
        i++;
    }
}

void    print_buff(char **buffer)
{
    int i;
    
    i = 0;
    while (buffer[i] != NULL)
    {
        printf("%s\n", buffer[i]);
        i++;
    }
}
