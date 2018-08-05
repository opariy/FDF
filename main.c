/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:22:18 by opariy            #+#    #+#             */
/*   Updated: 2018/07/04 14:22:31 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cell	*get_list(char **map, t_cell *cell)
{
	int		i;
	int		j;
	char	**split_str;
	t_cell	*head;

	i = -1;
	head = cell;
	while (map[++i])
	{
		j = -1;
		split_str = ft_strsplit(map[i], ' ');
		while (split_str[++j])
		{
			cell->x = j;
			cell->y = i;
			cell->z = ft_atoi(split_str[j]) * 0.4;
			cell->color = get_color(split_str[j]);
			if (split_str[j + 1])
				cell = create_elem(cell);
		}
		if (map[i + 1])
			cell = create_elem(cell);
		free(split_str);
	}
	return (head);
}

int		validate(const char *file_name, t_fdf *fdf)
{
	char	**map;
	int		width;

	if (!(map = get_map(file_name)))
	{
		ft_putstr("Usage : ./fdf <filename>.\n");
		exit(0);
	}
	width = validate_width(map, fdf);
	if (width == 0)
	{
		ft_putstr("Usage : ./fdf <filename>.\n");
		exit(0);
	}
	else
		return (width);
}

int		ft_exit(int keycode)
{
	keycode = 0;
	exit(keycode);
}

void	ft_intialize(t_fdf *fdf)
{
	fdf->rx = -0.5;
	fdf->ry = 0;
	fdf->rz = 0.05;
	fdf->width = 0;
	fdf->height = 0;
	fdf->size = 2;
	fdf->dx = 0;
	fdf->sx = 0;
	fdf->dy = 0;
	fdf->sy = 0;
	fdf->err = 0;
	fdf->e2 = 0;
	fdf->x0 = 0;
	fdf->y0 = 0;
}

int		main(int argc, char **argv)
{
	char	**map;
	t_cell	*list;
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	ft_intialize(fdf);
	if (argc != 2)
	{
		ft_putstr("Usage : ./fdf <filename>.\n");
	}
	else
	{
		fdf->width = validate(argv[1], fdf);
		map = get_map(argv[1]);
		list = initial_cell();
		list = get_list(map, list);
		fdf->head = list;
		modif_list(list, fdf->width);
		ft_draw(list, fdf);
	}
}
