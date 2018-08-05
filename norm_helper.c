/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:31:01 by opariy            #+#    #+#             */
/*   Updated: 2018/07/08 14:31:03 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		help_gnl2(char *tail, char **line, char *str)
{
	ft_memdel((void **)&str);
	ft_memdel((void **)line);
	*line = ft_strdup(tail);
	tail[0] = 0;
	return (1);
}

t_cell	*initial_cell(void)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	cell->x = 0;
	cell->y = 0;
	cell->z = 0;
	cell->color = 0;
	cell->next = NULL;
	cell->right = NULL;
	cell->bottom = NULL;
	return (cell);
}
