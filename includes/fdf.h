/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:19:43 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/04 14:26:51 by wrhett           ###   ########.fr       */
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
// # define ERR_USAGE			"Usage: (1 map file) ./fdf <filename>"
// # define ERR_MAP			"Incorrect filename. Error"
// # define ERR_MAP_READING	"Reading error"
// # define ERR_MAP_INIT		"Map initialization error"
// # define ERR_FILE			"Incorrect file. Wrong line length. Exit"
// # define ERR_FDF_INIT		"FdF initialization error. Error"
// # define ERR_CONV_TO_ARR	"Conversion to array"
# define ABS(Value) (Value > 0 ? Value : -Value)
# define WIDHT	1500
# define HIGHT	1200
# define KZ	10
# define KZ_MAX	1
# define KZ_MIN	0.5
# define KH_MAX	0.5
# define KH_MIN	0.1
# define ANGLE	0.5235987755983
# define ANGLE1	0.785398
# define K_LOOK 0.087266462599716
# define COLOR1	0x800080
# define COLOR2	0xFFFFFF
# define STR1	"zoom + or - "
# define STR2	"shift -> or <- UP or DOWN"
# define STR3	"heigt + or -"
# define STR4	"Isometric view - key I"
# define STR5	"Oblique isometric view - key O"

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
	double		angle;
	double		k_look;
	double		shift;
	double		hgt;
	double		x0;
	double		y0;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			deltax;
	int			deltay;
	int			sign_x;
	int			sign_y;
	int			error;
	int			error2;
	int 		step;
	int			flag;
	int			n;

}				t_fdf;

int				close_endian(void *param);
void			zoom_key(int key, t_fdf *p);
void			zoom_mouse(int key, t_fdf *p);
void			look(int key, t_fdf *p);
int				key_press(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_movement(int x, int y, void *param);
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
int				ft_get_color_2(int z_range, int n);
int				ft_get_point_colors(t_fdf *p, int n, int m);
void			ft_drawing_line(t_fdf *p);
void			ft_drawing_fon(t_fdf *p);
void			ft_parametr_iso(t_fdf *p);
void			ft_drawing_iso(t_fdf *p);
void			ft_parametr_iso_obl(t_fdf *p);
void			ft_drawing_iso_obl(t_fdf *p);
void			ft_operation_key(t_fdf *p);
void			ft_operation_mouse(t_fdf *p);

#endif
