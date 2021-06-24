/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylhouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:56:38 by ylhouari          #+#    #+#             */
/*   Updated: 2019/11/13 17:30:47 by ylhouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_freedom(int x, char *str, char *stat)
{
	free(str);
	free(stat);
	return (x);
}

char	*statq(char **line, char *stat, char *str, int i)
{
	*line = ft_strjoin_gnl(*line, ft_substr_gnl(str, 0, i));
	stat = ft_substr_gnl(str, i + 1, ft_strlen_gnl(str) - i + 1);
	free(str);
	return (stat);
}

int		find_char(char *s)
{
	int i;

	i = 0;
	while (s[i] != 0 && s[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char		*stat;
	char			*str;
	int				i;

	*line = ft_strdup_gnl("");
	while (1)
	{
		str = stat;
		if (stat == NULL)
		{
			str = malloc(1024 + 1);
			i = read(fd, str, 1024);
			if (i == 0 || i == -1)
				return (ft_freedom(i, str, stat));
			str[i] = 0;
		}
		i = find_char(str);
		if (str[i] == '\n')
		{
			stat = statq(line, stat, str, i);
			return (1);
		}
		*line = ft_strjoin_gnl(*line, str);
		stat = NULL;
	}
}
