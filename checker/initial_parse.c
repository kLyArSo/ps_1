#include "header.h"

char	*trim_spaces(char	*input)
{
	int		start;
	int		end;
	char	*result;

	start = 0;
	if (input == NULL)
		return (NULL);
	while (input[start] != 0
		&& is_white_space(input[start]) == 1)
		start++;
	end = ft_strlen(input) - 1;
	while (end >= 0
		&& is_white_space(input[end]) == 1)
		end--;
	result = ft_substr(input, start, end);
	return (result);
}

int     is_empty_array(char **argv)
{
    int i;

    i = 0;
    while (argv[i] != NULL)
    {
        if (ft_strlen(argv[i]) == 0)
            return (-1);
        else
            i++;
    }
    return (0);
}

char    **fetch_array(int argc, char **argv)
{
    char **buffer;
    int i;
    int j;

    i = 0;
    j = 1;  
    buffer = malloc(argc * sizeof(char*));
    while (argv[j] != NULL)
    {
        buffer[i] = trim_spaces(argv[j]);
        i++;
        j++;
    }
    buffer[i] = NULL;
    return (buffer);
}

int     *convert_to_int(int argc, char **buffer, char *c)
{
    int  *int_cast;
    int i;

    int_cast = malloc((argc - 1) * sizeof(int));
    i = 0;
    while (buffer[i] != 0)
    {
        int_cast[i] = ft_atoi(buffer[i], c);
        i++;
    }
    return (int_cast);
}
