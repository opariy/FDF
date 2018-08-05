/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:47:31 by opariy            #+#    #+#             */
/*   Updated: 2018/07/04 17:47:33 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cell	*create_elem(t_cell *head)
{
	while (head->next)
		head = head->next;
	head->next = malloc(sizeof(t_cell));
	head->next->x = 0;
	head->next->y = 0;
	head->next->z = 0;
	head->next->color = 0;
	head->next->next = NULL;
	head->next->right = NULL;
	head->next->bottom = NULL;
	return (head->next);
}

void	modif_list(t_cell *list, int width)
{
	int		i;
	int		n;
	t_cell	*tmp;

	n = 1;
	while (list->next)
	{
		if (n < width)
			list->right = list->next;
		else
			n = 0;
		i = -1;
		tmp = list;
		while (tmp && ++i < width)
			tmp = tmp->next;
		if (tmp)
			list->bottom = tmp;
		n++;
		list = list->next;
	}
}

void	reassign_xy_long(t_cell *list, t_fdf *fdf)
{
	double	x0;
	double	y0;
	double	z0;
	double	x1;
	double	y1;

	x0 = list->x;
	y0 = list->y * cos(fdf->rx) + list->z * sin(fdf->rx);
	z0 = -list->y * sin(fdf->rx) + list->z * cos(fdf->rx);
	x1 = x0 * cos(fdf->ry) + z0 * sin(fdf->ry);
	y1 = y0;
	list->z = -x0 * sin(fdf->ry) + z0 * cos(fdf->ry);
	list->x = x1 * cos(fdf->rz) - y1 * sin(fdf->rz);
	list->y = x1 * sin(fdf->rz) + y1 * cos(fdf->rz);
}

void	convert_to_xy(t_cell *list, t_fdf *fdf)
{
	while (list)
	{
		reassign_xy_long(list, fdf);
		list = list->next;
	}
}
