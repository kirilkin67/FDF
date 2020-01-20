/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:19:43 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/20 16:05:29 by wrhett           ###   ########.fr       */
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
# include "manual.h"
# define ABS(Value) (Value > 0 ? Value : -Value)
# define WIDHT	1900
# define HIGHT	1200
# define K_SHIFT	10
# define KZ	10
# define KZ_MAX	1
# define KZ_MIN	0.1
# define KH_MAX	1
# define KH_MIN	0.1
# define ANGLE	0.5235987755983
# define ANGLE1	0.785398
// # define ANGLE1	1.57079632
# define K_ROT 0.087266463
# define COLOR1	0x800080
# define COLOR2	0xFFFFFF
# define NUM_KEY_2	91
# define NUM_KEY_4	86
# define NUM_KEY_6	88
# define NUM_KEY_8	84

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_dot
{
	double		x;
	double		y;
	double		z;
	int			color;
	double		x1;
	double		y1;
	double		z1;
}				t_dot;

typedef struct	s_draw
{
	int			deltax;
	int			deltay;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
	int			step;
	int			n;
}				t_draw;

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

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*draw;
	int			bpp;
	int			size_line;
	int			endian;
	int			*coords;
	int			*colors;
	int			width;
	int			hight;
	int			z_min;
	int			z_max;
	int			z_range;
	int			color1;
	int			color2;
	int			mouse_key;
	int			mouse_x;
	int			mouse_y;
	double		alfa_x;
	double		alfa_y;
	double		angle;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		shift;
	double		hgt;
	double		x0;
	double		y0;
	double		z1;
	double		z2;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			flag;
	int			n;

}				t_fdf;

int				close_endian(void *param);
void			zoom_key(int key, t_fdf *p);
void			zoom_mouse(int key, t_fdf *p);
void			look(int key, t_fdf *p);
int				key_press(int key, void *param);
int				mouse_press(int button, int x, int y, t_fdf *p);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_movement(int x, int y, t_fdf *p);
void			ft_exit(char *str);
t_bool			ft_isnumber(char *str, int base);
int				ft_atoi_base(const char *str, int base);
int				ft_read_map_prev(const int fd, t_map *map);
int				ft_read_map_2(const int fd, t_map *map);
t_map			*ft_map_init(void);
t_map			*ft_map_init_2(t_map *map);
double			min_shift(t_fdf *p);
double			min_shift_oblique(t_fdf *p);
double			point_height(t_fdf *p, int x, int y);
int				ft_get_color(int color1, int color2, int step, int n);
int				ft_get_color_2(int z_range, int n);
int				ft_get_point_colors(t_fdf *p, int n, int m);
void			ft_drawing_line(t_fdf *p);
void			ft_drawing_line_dot(t_fdf *p, t_dot *dot1, t_dot *dot2);
void			ft_drawing_fon(t_fdf *p);
void			ft_parametr_iso(t_fdf *p);
void			ft_drawing_iso(t_fdf *p);
void			ft_parametr_iso_obl(t_fdf *p);
void			ft_drawing_iso_obl(t_fdf *p);
void			ft_rotation(t_fdf *p);
void			ft_rotation_dot(t_fdf *p, t_dot *dot);
void			ft_operation_key(t_fdf *p);
void			ft_operation_mouse(t_fdf *p);

#endif
