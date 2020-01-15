/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:55 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/15 20:05:10 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// double		min_shift(t_fdf *p) // Первая версия
// {
// 	double	min_shift;

// 	min_shift = WIDHT / (p->width + p->hight + 2) / cos(p->angle);
// 	if ((min_shift * (p->width + p->hight - 2) * sin(p->angle) + \
// 			p->z_range * min_shift) > HIGHT)
// 		min_shift = HIGHT / ((p->width + p->hight + 2) * sin(p->angle) + \
// 					p->z_range + 2);
// 	return (min_shift);
// }

double		min_shift(t_fdf *p)
{
	double	min_shift;

	min_shift = WIDHT / (p->width + p->hight + 2) / cos(p->angle);
	if (min_shift * (p->width + p->hight) * sin(p->angle) >= HIGHT)
		min_shift = HIGHT / (p->width + p->hight + 2) / sin(p->angle);
	if (min_shift < 1)
		min_shift = 1;
	return (min_shift);
}

void	ft_parametr_iso(t_fdf *p)
{
	p->flag = 0;
	p->angle_x = 0;
	p->angle_y = 0;
	p->angle_z = 0;
	p->angle = ANGLE;
	p->shift = min_shift(p);
	if (p->z_range != 0)
		p->hgt = ABS((HIGHT - (p->width + p->hight - 2) * p->shift * \
				sin(p->angle))/ p->z_range);
	p->x0 = (WIDHT - (p->width + p->hight - 2) * p->shift * cos(p->angle)) / 2;
	if (p->z_range == 0)
		p->y0 = (HIGHT + ((p->width - p->hight) * p->shift * sin(p->angle))) / 2;
	else
		p->y0 = (p->width - 1) * p->shift * sin(p->angle) + p->hgt * p->z_max;
}

static double	high(t_fdf *p, int x, int y)
{
	double z;

	z = p->coords[p->width * y + x] * p->hgt;
	return (z);
}

static void	rotation_x(t_fdf *p)
{
	double y1;
	double y2;
	double z1;
	double z2;

	y1 = p->y1;
	z1 = p->z1;
	y2 = p->y2;
	z2 = p->z2;
	p->y1 = y1 * cos(p->angle_x) + z1 * sin(p->angle_x);
	p->z1 = -y1 * sin(p->angle_x) + z1 * cos(p->angle_x);
	p->y2 = y2 * cos(p->angle_x) + z2 * sin(p->angle_x);
	p->z2 = -y2 * sin(p->angle_x) + z2 * cos(p->angle_x);
}

static void	rotation_y(t_fdf *p)
{
	double x1;
	double x2;
	double z1;
	double z2;

	x1 = p->x1;
	z1 = p->z1;
	x2 = p->x2;
	z2 = p->z2;
	p->x1 = x1 * cos(p->angle_y) + z1 * sin(p->angle_y);
	p->z1 = -x1 * sin(p->angle_y) + z1 * cos(p->angle_y);
	p->x2 = x2 * cos(p->angle_y) + z2 * sin(p->angle_y);
	p->z2 = -x2 * sin(p->angle_y) + z2 * cos(p->angle_y);
}

static void	rotation_z(t_fdf *p)
{
	double x1;
	double x2;
	double y1;
	double y2;
	
	x1 = p->x1;
	y1 = p->y1;
	x2 = p->x2;
	y2 = p->y2;
	
	p->x1 = p->x0 + (x1 * cos(p->angle_z) - y1 * sin(p->angle_z));
	p->y1 = p->y0 - (x1 * sin(p->angle_z) + y1 * cos(p->angle_z));// - p->z1;
	p->x2 = p->x0 + (x2 * cos(p->angle_z) - y2 * sin(p->angle_z));
	p->y2 = p->y0 - (x2 * sin(p->angle_z) + y2 * cos(p->angle_z));// - p->z2;
}

static void	ft_drawing_width_line(t_fdf *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < p->hight)
	{
		x = 0;
		while (x < (p->width - 1))
		{
			p->z1 = high(p, x, y);
			p->x1 = p->shift * cos(p->angle) * (x + y);
			p->y1 = p->shift * sin(p->angle) * (x - y);
			p->color1 = ft_get_point_colors(p, x, y);
			p->z2 = high(p, x + 1, y);
			p->x2 = p->shift * cos(p->angle) * (x + y + 1);
			p->y2 = p->shift * sin(p->angle) * (x - y + 1);
			p->color2 = ft_get_point_colors(p, x + 1, y);
			rotation_x(p);
			rotation_y(p);
			rotation_z(p);
			ft_drawing_line(p);
			x += 1;
		}
		y += 1;
	}
}

static void	ft_drawing_hight_line(t_fdf *p)
{
	int	x;
	int	y;

	x = p->width - 1;
	while (x >= 0)
	{
		y = 0;
		while (y < (p->hight - 1))
		{
			p->z1 = high(p, x, y);
			p->x1 = p->shift * cos(p->angle) * (x + y);
			p->y1 = p->shift * sin(p->angle) * (x - y);
			p->color1 = ft_get_point_colors(p, x, y);
			p->z2 = high(p, x, y + 1);
			p->x2 = p->shift * cos(p->angle) * (x + y + 1);
			p->y2 = p->shift * sin(p->angle) * (x - y - 1);
			p->color2 = ft_get_point_colors(p, x, y + 1);
			rotation_x(p);
			rotation_y(p);
			rotation_z(p);
			ft_drawing_line(p);
			y += 1;
		}
		x -= 1;
	}
}

void		ft_drawing_iso(t_fdf *p)
{
	ft_bzero(p->draw, WIDHT * HIGHT * 4);
	ft_drawing_hight_line(p);
	ft_drawing_width_line(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR2);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR3);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 80, 0xFFFFFF, STR4);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 100, 0xFFFFFF, STR5);
}
