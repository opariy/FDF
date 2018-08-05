/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 14:33:29 by opariy            #+#    #+#             */
/*   Updated: 2017/06/23 14:34:12 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	helper_g(char buf[BUFF_SIZE + 1], int c[2])
{
	while (c[0] < BUFF_SIZE - c[1])
	{
		buf[c[1] + c[0]] = '\0';
		c[0]++;
	}
}

char	*help_g(int c[2], char *tail, char *str)
{
	c[0] = 0;
	ft_memdel((void **)&str);
	str = tail;
	return (str);
}

int		help(char *str)
{
	ft_memdel((void **)&str);
	return (1);
}

int		help_gnl(char *str, char **line)
{
	ft_memdel((void **)&str);
	ft_memdel((void **)line);
	*line = ft_strnew(0);
	return (0);
}

int		get_next_line(const int fd, char **line, char *str, int c[2])
{
	static char		*tail = NULL;
	char			buf[BUFF_SIZE + 1];

	buf[BUFF_SIZE] = '\0';
	if (!tail)
		tail = ft_strnew(0);
	while ((c[1] = read(fd, buf, BUFF_SIZE)) >= 0)
	{
		if (c[1] < BUFF_SIZE)
			helper_g(buf, c);
		str = help_g(c, tail, str);
		tail = ft_strjoin(tail, buf);
		if (ft_strchr(tail, '\n'))
		{
			ft_memdel((void **)line);
			*line = ft_strsub(tail, 0, ft_strchr(tail, '\n') - tail);
			ft_memdel((void **)&tail);
			return (help(str));
		}
		if (!c[1] && !tail[0])
			return (help_gnl(str, line));
		if (c[1] == 0)
			return (help_gnl2(tail, line, str));
	}
	return (-1);
}
