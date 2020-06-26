/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso_obl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:04:49 by wrhett            #+#    #+#             */
/*   Updated: 2020/06/26 11:51:07 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		min_shift_oblique(t_fdf *p)
{
	double	shift;

	shift = (double)WIDHT / (double)(p->width + 1);
	if (shift * (p->hight + 1) >= (double)HIGHT)
		shift = (double)HIGHT / (double)(p->hight + 1);
	if (shift < 1)
		shift = 1;
	return (shift);
}

void		ft_parametr_iso_obl(t_fdf *p)
{
	p->flag = 1;
	p->angle_x = 0;
	p->angle_y = 0;
	p->angle_z = 0;
	p->angle = 1.57079632;
	p->shift = min_shift_oblique(p);
	if (p->z_range != 0)
	{
		if (p->z_max >= -p->z_min && p->z_max != 0)
			p->hgt = (HIGHT / 2.0 - p->shift) / p->z_max;
		else
			p->hgt = (HIGHT / 2.0 - p->shift) / -p->z_min;
	}
	p->x0 = (double)WIDHT / 2;
	p->y0 = (double)HIGHT / 2;
}

void		ft_point_coordinates(t_fdf *p, t_dot *point, int x, int y)
{
	point->z = point_height(p, x, y);
	point->x = p->shift * ((double)x - (double)(p->width - 1) / 2);
	point->y = p->shift * ((double)y - (double)(p->hight - 1) / 2);
	point->color = ft_get_point_colors(p, x, y);
	ft_rotation_dot(p, point);
}

void		ft_point_drawing_betta(t_fdf *p)
{
	t_dot	dot1;
	t_dot	dot2;
	int		x;
	int		y;

	y = 0;
	while (y < p->hight)
	{
		x = 0;
		while (x < p->width)
		{
			ft_point_coordinates(p, &dot1, x, y);
			if ((x + 1) != p->width)
			{
				ft_point_coordinates(p, &dot2, x + 1, y);
				ft_drawing_line_dot(p, &dot1, &dot2);
			}
			if ((y + 1) != p->hight)
			{
				ft_point_coordinates(p, &dot2, x, y + 1);
				ft_drawing_line_dot(p, &dot1, &dot2);
			}
			x += 1;
		}
		y += 1;
	}
}

void		ft_point_drawing(t_fdf *p)
{
	t_dot	dot1;
	t_dot	dot2;
	int		n;

	n = 0;
	while (n < p->width * p->hight)
	{
		ft_point_coordinates(p, &dot1, n % p->width, n / p->width);
		if (n % p->width < (p->width - 1))
		{
			ft_point_coordinates(p, &dot2, (n + 1) % p->width, (n + 1) / p->width);
			ft_drawing_line_dot(p, &dot1, &dot2);
		}
		if (n / p->width < (p->hight - 1))
		{
			ft_point_coordinates(p, &dot2, (n + p->width) % p->width, (n + p->width) / p->width);
			ft_drawing_line_dot(p, &dot1, &dot2);
		}
		n += 1;
	}
}

void		ft_drawing_iso_obl(t_fdf *p)
{
	ft_bzero(p->draw, WIDHT * HIGHT * 4);
	ft_point_drawing(p);
	ft_point_drawing_betta(p);
	expose_hook(p);
}
