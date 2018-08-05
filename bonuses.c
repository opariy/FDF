/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:40:56 by opariy            #+#    #+#             */
/*   Updated: 2018/07/06 17:40:58 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_with_xy(int key, t_cell *list)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (key == 124)
		x = 1;
	else if (key == 126)
		y = -1;
	else if (key == 123)
		x = -1;
	else
		y = 1;
	while (list)
	{
		list->x += x;
		list->y += y;
		list = list->next;
	}
}

void	rainbow(int key, t_fdf *fdf)
{
	int		color;
	t_cell	*list;

	color = 16777215;
	list = fdf->head;
	if (key == 18)
		color = 16731490;
	else if (key == 19)
		color = 11433255;
	else if (key == 20)
		color = 15854375;
	else if (key == 21)
		color = 3903006;
	else if (key == 23)
		color = 5873110;
	else if (key == 22)
		color = 1064805;
	else if (key == 26)
		color = 8603847;
	while (list)
	{
		list->color = color;
		list = list->next;
	}
}

void	size(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->size *= 0.9;
	else if (key == 78)
		fdf->size *= 1.1;
}

void	rotation(int key, t_cell *list, t_fdf *fdf)
{
	if (key == 83)
		fdf->rx += 0.05;
	else if (key == 84)
		fdf->rx -= 0.05;
	else if (key == 86)
		fdf->ry += 0.05;
	else if (key == 87)
		fdf->ry -= 0.05;
	else if (key == 89)
		fdf->rz += 0.05;
	else if (key == 91)
		fdf->rz -= 0.05;
	convert_to_xy(list, fdf);
	fdf->rx = 0;
	fdf->ry = 0;
	fdf->rz = 0;
}

void	change_z(int key, t_cell *list, t_fdf *fdf)
{
	int z;

	z = 0;
	if (key == 116)
		z = 1;
	else if (key == 121)
		z = -1;
	while (list)
	{
		if (list->z != 0)
			list->z *= 1.1;
		list = list->next;
	}
	convert_to_xy(list, fdf);
}
