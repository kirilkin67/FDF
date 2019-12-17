/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:19:43 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/17 18:56:58 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "error.h"
# define ABS(Value) (Value > 0 ? Value : -Value)
# define WIDHT	1500
# define HIGHT	1200
# define KZ	0.5
# define KH	0.5
# define ANGLE	0.523599
# define ANGLE1	0.78539816339745
# define COLOR1	0xFFFFFF
# define COLOR2	0xFF00

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_map
{
	int			width;
	int			height;
	int			*coords_arr;
	int			*colors_arr;
	int			z_min;
	int			z_max;
	int			z_range;
}				t_map;

typedef struct	s_dot
{
	double		x0;
	double		y0;
	double		z0;
	int			color;
	double		x1;
	double		y1;
	double		z1;
}				t_dot;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*draw;
	int			bpp;
	int			size_line;
	int			endian;
	char		*zoom;
	char		*offset;
	char		*height;
	int			*coords;
	int			*colors;
	int			width;
	int			hight;
	int			z_min;
	int			z_max;
	int			z_range;
	int			color1;
	int			color2;
	double		angle;
	double		shift;
	double		hgt;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	int			flag;
	int			m;

}				t_fdf;

int				close_endian(void *param);
void			zoom(int key, t_fdf *p);
int				key_press(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
void			ft_exit(char *str);
t_bool			ft_isnumber(char *str, int base);
int				ft_atoi_base(const char *str, int base);
int				ft_read_map_prev(const int fd, t_map *map);
int				ft_read_map_2(const int fd, t_map *map);
t_map			*ft_map_init(void);
t_map			*ft_map_init_2(t_map *map);
double			min_shift(t_fdf *p);
double			min_shift_oblique(t_fdf *p);
int				ft_get_color(int color1, int color2, int step, int n);
int				ft_get_color_2(int z_max, int n);
int				ft_get_point_colors(t_fdf *p, int n, int m);
void			ft_drawing_line(t_fdf *p);
void			ft_drawing_fon(t_fdf *p);
void			ft_drawing_iso(t_fdf *p);
void			ft_drawing_iso_obl(t_fdf *p);
void			ft_operation(t_fdf *p);
void			ft_operation_mouse(t_fdf *p);

#endif
