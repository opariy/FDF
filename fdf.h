/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:38:32 by opariy            #+#    #+#             */
/*   Updated: 2018/07/04 15:44:54 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# define BUFF_SIZE 1

# define WIDTH 1800
# define HEIGHT 1000
# define COEF WIDTH/fdf->size/fdf->width
# define SHIFT_W (WIDTH - (fdf->width)*COEF)/2
# define SHIFT_H (HEIGHT - (fdf->height)*COEF)/2

typedef struct		s_cell
{
	double			x;
	double			y;
	double			z;
	int				color;
	struct s_cell	*next;
	struct s_cell	*right;
	struct s_cell	*bottom;
}					t_cell;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			rx;
	double			ry;
	double			rz;
	double			size;
	int				width;
	int				height;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
	int				x0;
	int				y0;
	t_cell			*head;

}					t_fdf;

int					get_next_line(const int fd, char **line, char *str,
										int c[2]);
int					ft_atoi_base(char *str, int str_base);
char				**get_map(const char *file_name);
int					validate_width(char **map, t_fdf *fdf);
t_cell				*create_elem(t_cell *head);
void				modif_list(t_cell *list, int width);
void				convert_to_xy(t_cell *list, t_fdf *fdf);
void				draw_line(t_cell *list, t_fdf *fdf);
void				ft_draw(t_cell *list, t_fdf *fdf);
void				deal_with_xy(int key, t_cell *list);
void				rainbow(int key, t_fdf *fdf);
void				change_z(int key, t_cell *list, t_fdf *fdf);
void				rotation(int key, t_cell *list, t_fdf *fdf);
void				size(int key, t_fdf *fdf);
int					help_gnl2(char *tail, char **line, char *str);
void				ft_draw(t_cell *list, t_fdf *fdf);
int					key_hook(int key, t_fdf *fdf);
int					get_color(char *str);
t_cell				*initial_cell(void);
int					ft_exit(int keycode);

#endif
