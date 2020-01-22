/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso_obl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:04:49 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/22 14:22:23 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_drawing_width_line_obl(t_fdf *p)
{
	int	n;
	int	m;

	m = 0;
	while (m < p->hight)
	{
		n = 0;
		while (n < (p->width - 1))
		{
			p->z1 = point_height(p, n, m);
			p->x1 = p->shift * (n - p->width / 2);
			p->y1 = p->shift * (m - p->hight / 2);
			p->color1 = ft_get_point_colors(p, n, m);
			p->z2 = point_height(p, n + 1, m);
			p->x2 = p->shift * (n + 1 - p->width / 2);
			p->y2 = p->shift * (m - p->hight / 2);
			p->color2 = ft_get_point_colors(p, n + 1, m);
			ft_rotation(p);
			ft_drawing_line(p);
			n += 1;
		}
		m += 1;
	}
}

static void	ft_drawing_hight_line_obl(t_fdf *p)
{
	int	n;
	int	m;

	n = 0;
	while (n < p->width)
	{
		m = 0;
		while (m < (p->hight - 1))
		{
			p->z1 = point_height(p, n, m);
			p->x1 = p->shift * (n - p->width / 2);
			p->y1 = p->shift * (m - p->hight / 2);
			p->color1 = ft_get_point_colors(p, n, m);
			p->z2 = point_height(p, n, m + 1);
			p->x2 = p->shift * (n - p->width / 2);
			p->y2 = p->shift * (m + 1 - p->hight / 2);
			p->color2 = ft_get_point_colors(p, n, m + 1);
			ft_rotation(p);
			ft_drawing_line(p);
			m += 1;
		}
		n += 1;
	}
}

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
	p->angle_x = 0;
	p->angle_y = 0;
	p->angle_z = 0;
	p->angle = 1.57079632;
	p->shift = min_shift_oblique(p);
	if (p->z_range != 0)
		p->hgt = ABS((HIGHT - (p->hight - 1) * p->shift) / p->z_range);
	p->x0 = WIDHT / 2;
	p->y0 = HIGHT / 2;
}

void	ft_point_coordinates(t_fdf *p, t_dot *point, int x, int y)
{
	
	point->z = point_height(p, x, y);
	point->x = p->shift * ((double)x - (double)(p->width - 1) / 2);
	point->y = p->shift * ((double)y - (double)(p->hight - 1) / 2);
	point->color = ft_get_point_colors(p, x, y);
	ft_rotation_dot(p, point);
}

void	ft_point_drawing(t_fdf *p)
{
	t_dot	dot1;
	t_dot	dot2;
	int x;
	int y;

	y = 0;
	while (y < (p->hight))
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

void	ft_point_drawing_betta(t_fdf *p)
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
	// ft_drawing_hight_line_obl(p);
	// ft_drawing_width_line_obl(p);
	// ft_point_drawing(p);
	ft_point_drawing_betta(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR2);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR3);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 80, 0xFFFFFF, STR4);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 100, 0xFFFFFF, STR5);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 120, 0xFFFFFF, STR6);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 140, 0xFFFFFF, STR7);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 160, 0xFFFFFF, STR8);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 180, 0xFFFFFF, STR9);
}
