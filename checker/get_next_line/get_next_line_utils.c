/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylhouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:38:47 by ylhouari          #+#    #+#             */
/*   Updated: 2019/11/13 17:33:26 by ylhouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	j = -1;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	while (s2[++j] != '\0')
		p[i++] = s2[j];
	p[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (p);
}

char	*ft_strdup_gnl(const char *s1)
{
	char		*p;
	size_t		i;

	i = 0;
	p = malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	else
	{
		while (i <= ft_strlen_gnl(s1))
		{
			*(p + i) = *(s1 + i);
			i++;
		}
		return (p);
	}
}

size_t	ft_strlen_gnl(const char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen_gnl(s))
		len = 0;
	if (start < ft_strlen_gnl(s) && start + len > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len && s[start] != 0)
		p[i++] = s[start++];
	*(p + i) = '\0';
	return (p);
}
