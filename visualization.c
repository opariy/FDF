/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 19:34:32 by opariy            #+#    #+#             */
/*   Updated: 2018/07/05 19:34:34 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line(t_cell *list, int x1, int y1, t_fdf *fdf)
{
	fdf->x0 = (int)(list->x * COEF + SHIFT_W);
	fdf->y0 = (int)(list->y * COEF + SHIFT_H);
	fdf->dx = abs(x1 - fdf->x0);
	fdf->sx = fdf->x0 < x1 ? 1 : -1;
	fdf->dy = abs(y1 - fdf->y0);
	fdf->sy = fdf->y0 < y1 ? 1 : -1;
	fdf->err = (fdf->dx > fdf->dy ? fdf->dx : -fdf->dy) / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr,
					fdf->x0, fdf->y0, list->color);
		if (fdf->x0 == x1 && fdf->y0 == y1)
			break ;
		fdf->e2 = fdf->err;
		if (fdf->e2 > -fdf->dx)
		{
			fdf->err -= fdf->dy;
			fdf->x0 += fdf->sx;
		}
		if (fdf->e2 < fdf->dy)
		{
			fdf->err += fdf->dx;
			fdf->y0 += fdf->sy;
		}
	}
}

void		draw_line(t_cell *list, t_fdf *fdf)
{
	while (list->next)
	{
		if (list->right)
			line(list, (int)(list->right->x * COEF + SHIFT_W),
				(int)(list->right->y * COEF + SHIFT_H), fdf);
		if (list->bottom)
			line(list, (int)(list->bottom->x * COEF + SHIFT_W),
				(int)(list->bottom->y * COEF + SHIFT_H), fdf);
		list = list->next;
	}
}

void		ft_draw(t_cell *list, t_fdf *fdf)
{
	convert_to_xy(list, fdf);
	fdf->rx = 0;
	fdf->ry = 0;
	fdf->rz = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf");
	draw_line(list, fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_hook, fdf);
	mlx_hook(fdf->win_ptr, 17, 1L << 17, ft_exit, 0);
	mlx_loop(fdf->mlx_ptr);
}

int			key_hook(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	else if (key == 124 || key == 126 ||
			key == 125 || key == 123)
		deal_with_xy(key, fdf->head);
	else if ((key >= 18 && key <= 23) || key == 26)
		rainbow(key, fdf);
	else if (key == 116 || key == 121)
		change_z(key, fdf->head, fdf);
	else if (key == 83 || key == 84 || key == 86 ||
			key == 87 || key == 89 || key == 91)
		rotation(key, fdf->head, fdf);
	else if (key == 69 || key == 78)
		size(key, fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw_line(fdf->head, fdf);
	return (0);
}

int			get_color(char *str)
{
	char	**split;
	int		color;

	if (ft_strchr(str, ','))
	{
		split = ft_strsplit(str, ',');
		color = ft_atoi_base(split[1], 16);
	}
	else
		color = 16777215;
	return (color);
}
