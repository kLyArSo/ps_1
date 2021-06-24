/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylhouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:31:34 by ylhouari          #+#    #+#             */
/*   Updated: 2019/11/13 17:31:51 by ylhouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strdup_gnl(const char *s1);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
int         *quick_sort(int  *buff, int n);
int         int_buff_cmp_1(int  *int_cast, int     *sorted, int len);

#endif
