/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:01:17 by opariy            #+#    #+#             */
/*   Updated: 2018/07/05 16:01:21 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_map(const char *file_name)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;
	int		c[2];

	c[0] = 0;
	c[1] = 1;
	i = 0;
	fd = open(file_name, O_RDONLY);
	map = NULL;
	if (fd > 0)
	{
		line = ft_strnew(0);
		map = (char**)malloc(sizeof(char*) * 1000000 + 1);
		while (get_next_line(fd, &line, ft_strnew(0), c) > 0)
		{
			if (strcmp(line, "") == 0)
				return (0);
			map[i++] = ft_strdup(line);
		}
		map[i] = NULL;
	}
	return (map);
}

int		validate_hex(char *str)
{
	int		i;

	i = 2;
	if (str[0] != '0')
		return (0);
	if (str[1] != 'x' && str[1] != 'X')
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else if ((str[i] >= 'A' && str[i] <= 'F')
				|| (str[i] >= 'a' && str[i] <= 'f'))
			i++;
		else
			return (0);
	}
	if (i > 8)
		return (0);
	else
		return (1);
}

int		validate_numerical(char *str)
{
	int			i;
	size_t		digits;
	size_t		sign;

	sign = 0;
	i = -1;
	digits = 0;
	while (str[++i])
	{
		if (str[0] == '+' || str[0] == '-')
			sign = 1;
		if (ft_isdigit(str[i]))
			digits++;
		else if (str[i] == ',')
		{
			if (validate_hex(ft_strsub(str, i + 1, ft_strlen(str) - i)))
				return (1);
			else
				return (0);
		}
	}
	if (digits + sign == ft_strlen(str))
		return (1);
	else
		return (0);
}

int		count_width(char *str)
{
	char	**split_str;
	int		width;
	int		i;

	i = 0;
	width = 0;
	split_str = ft_strsplit(str, ' ');
	while (split_str[i])
	{
		if (validate_numerical(split_str[i]) == 0)
			return (0);
		width++;
		i++;
	}
	return (width);
}

int		validate_width(char **map, t_fdf *fdf)
{
	int		i;
	int		width;
	int		current_width;

	i = 0;
	width = 0;
	while (map[i])
	{
		current_width = count_width(map[i]);
		if (i == 0)
			width = current_width;
		if (current_width != width)
			return (0);
		i++;
	}
	fdf->height = i;
	return (width);
}
