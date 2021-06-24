#include "header.h"

void    print_alg(int *buff, int imax)
{
    int i = 0;
    printf("{");
    while (i < imax)
    {
        printf("%d, ", buff[i]);
        i++;
    }
    printf("%d}\n", buff[i]);
}

void    swap(int   *T, int i, int j)
{
    int temp;

    temp = T[i];
    T[i] = T[j];
    T[j] = temp;
}

int    partition(int   *buff, int imin, int imax)
{
    int i;
    int j;
    int v;

    v = buff[imax];
    i = imin;
    j = imax;
    while (i <= j)
    {
        while (i < imax && buff[i] <= v)
            i++;
        while (j >= imin && buff[j] >= v)
            j--;
        if (i < j)
            swap(buff, i, j);
    }
    buff[imax] = buff[i];
    buff[i] = v;
    return (i);
}

void    tri_Rapide(int  *buff, int imin, int imax)
{
    int i;

    if (imin < imax)
    {
        i = partition(buff, imin, imax);
        tri_Rapide(buff, imin, i - 1);
        tri_Rapide(buff, i + 1, imax);
    }
}

int     int_buff_cmp(int  *int_cast, int     *sorted, int len)
{
    int i;

    i = 0;
    while (i < len && int_cast[i] == sorted[i])
        i++;
    if (i != len)//not sorted
    {
        sorted = free_int_buffer(sorted);
        return (0);
    }
    else
    {
        int_cast = free_int_buffer(int_cast);
        sorted = free_int_buffer(sorted);
        return (1);
    }
}

int     *int_buff_dup(int  *int_cast, int n)
{
    int     *ret;
    int     i;

    i = 0;
    ret = malloc(n * sizeof(int));
    while(i < n)
    {
        ret[i] = int_cast[i];
        i++;
    }
    return (ret);
}

int    *quick_sort(int  *buff, int n)
{
    tri_Rapide(buff, 0, n - 1);
    return(buff);
}

int    is_sorted(int  *int_cast, int argc)
{
    return (int_buff_cmp(int_cast,
    quick_sort(int_buff_dup(int_cast, argc - 1), argc - 1),
    argc - 1));
}