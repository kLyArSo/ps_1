#include "header.h"

int     dig_check(char  *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        if (str[i] < 48 && str[i] != 43 && str[i] != 45)
            return (-1);
        if (str[i] > 57)
            return (-1);
        i++;
    }
    return (0);
}

int     sign_check(char  *str)
{
    int i;
    int counter;
    i = 0;
    counter = 0;

    while (str[i] != 0)
    {
        if (str[i] == '+' || str[i] == '-')
            counter++;
        i++;
    }
    if (counter > 1)
        return (-1);
    else if (counter == 1)
    {
        if (str[0] != '+' && str[0] != '-')
            return (-1);
        if ((str[0] == '+' || str[0] == '-')
            && (str[1] < 48 || str[i] > 57))
        return (-1);
    }
    return (0);
}

int     arg_validity(char   **buffer)
{
    int i;

    i = 0;
    while (buffer[i] != NULL)
    {
        if (dig_check(buffer[i]) == -1)
            return (-1);
        if (sign_check(buffer[i]) == -1)
            return (-1);
        i++;
    }
    return (0);
}

int     check_for_int_dup(int c, int *int_cast, int i, int argc)
{
    while (i <= argc - 2 && c != int_cast[i])
        i++;
    if (i == argc - 1)
        return (0);
    else
        return (1);
}

int     check_for_dups(int argc, int  *int_cast)
{
    int i;
    int x;
    i = 0;
    while (i <= argc - 2 && (x = check_for_int_dup(int_cast[i], int_cast, i + 1, argc)) == 0)
        i++;
    if (x == 1)
        return (1);
    else
        return (0);
}
