#include "header.h"


int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

int		ft_list_len(t_stack *stack)
{
	int i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

char	*my_calloc(int	length)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(length);
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_substr(char	*str, int	start, int	end)
{
	int		i;
	char	*result;

	i = 0;
	if (str == NULL)
		return (NULL);
	result = my_calloc(end - start + 2);
	while (start <= end)
	{
		result[i] = str[start];
		start++;
		i++;
	}
	return (result);
}

int	is_white_space(char	c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		ft_atoi(char *src, char	*c)
{
	size_t			i;
	size_t			s;
	size_t			res;
    long            x;

	i = 0;
	res = 0;
	s = 1;
	while ((src[i] >= 9 && src[i] <= 13) || (src[i] == 32))
		i++;
	if (src[i] == '+')
		i++;
	else if (src[i] == '-')
	{
		s = -1;
		i++;
	}
	if (src[i] < 48 && src[i] > 57)
		return (0);
	else
		while ((src[i] >= 48) && (src[i] <= 57))
		{
			res = res * 10 + src[i] - '0';
			i++;
		}
    x = res * s;
    if (x > 2147483647 || x < -2147483648)
        *c = 'a';
	return (x);
}