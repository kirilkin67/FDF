/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso_obl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:04:49 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/15 20:53:38 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		min_shift_oblique(t_fdf *p)
{
	double	shift;

	shift = WIDHT / (p->width + 1);
	if (shift * (p->hight - 1) > HIGHT)
		shift = HIGHT / (p->hight + 1);
	if (shift < 1)
		shift = 1;
	return (shift);
}

void		ft_parametr_iso_obl(t_fdf *p)
{
	p->flag = 1;
	p->angle = ANGLE1;
	p->angle_x = 0;
	p->angle_y = 0;
	p->angle_z = 0;
	p->shift = min_shift_oblique(p);
	if (p->z_range != 0)
		p->hgt = ABS((HIGHT - (p->hight - 1) * p->shift)/ p->z_range);
	p->x0 = (WIDHT - (p->width - 1 ) * p->shift) / 2;
	// if (p->z_range == 0)
		p->y0 = (HIGHT - (p->hight - 1) * p->shift) / 2;
	// else
	// 	p->y0 = (p->z_max > p->z_min) ? p->hgt * (p->z_max - 1) : \
	// 	HIGHT - (p->z_min * p->hgt);
}

static double	high_obl(t_fdf *p, int x, int y)
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
	p->y1 = p->y0 + (x1 * sin(p->angle_z) + y1 * cos(p->angle_z));
	p->x2 = p->x0 + (x2 * cos(p->angle_z) - y2 * sin(p->angle_z));
	p->y2 = p->y0 + (x2 * sin(p->angle_z) + y2 * cos(p->angle_z));
}


static void	ft_drawing_width_line_obl(t_fdf *p, double x0, double y0)
{
	int	n;
	int	m;

	m = 0;
	while (m < p->hight)
	{
		n = 0;
		while (n < (p->width - 1))
		{
			p->z1 = high_obl(p, n, m);
			p->x1 = p->shift * n;
			p->y1 = p->shift * m;
			p->color1 = ft_get_point_colors(p, n, m);
			p->z2 = high_obl(p, n + 1, m);
			p->x2 = p->shift * (n + 1);
			p->y2 = p->shift * m;
			p->color2 = ft_get_point_colors(p, n + 1, m);
			rotation_x(p);
			rotation_y(p);
			rotation_z(p);
			ft_drawing_line(p);
			n += 1;
		}
		m += 1;
	}
}

static void	ft_drawing_hight_line_obl(t_fdf *p, double x0, double y0)
{
	int	n;
	int	m;

	n = 0;
	while (n < p->width)
	{
		m = 0;
		while (m < (p->hight - 1))
		{
			p->z1 = high_obl(p, n, m);
			p->x1 = p->shift * n;
			p->y1 = p->shift * m;
			p->color1 = ft_get_point_colors(p, n, m);
			p->z2 = high_obl(p, n, m + 1);
			p->x2 = p->shift * n;
			p->y2 = p->shift * (m + 1);
			p->color2 = ft_get_point_colors(p, n, m + 1);
			rotation_x(p);
			rotation_y(p);
			rotation_z(p);
			ft_drawing_line(p);
			m += 1;
		}
		n += 1;
	}
}

void		ft_drawing_iso_obl(t_fdf *p)
{
	double	x0;
	double	y0;

	x0 = p->x0;
	y0 = p->y0;
	ft_bzero(p->draw, WIDHT * HIGHT * 4);
	ft_drawing_hight_line_obl(p, x0, y0);
	ft_drawing_width_line_obl(p, x0, y0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR2);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR3);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 80, 0xFFFFFF, STR4);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 100, 0xFFFFFF, STR5);
}
