/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:55 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/12 16:49:32 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_drawing_line(t_fdf *p)
{
	double	deltax;
	double	deltay;
	int		color;
	int		step;
	int		n;

	deltax = p->x2 - p->x1;
	deltay = p->y2 - p->y1;
	step = (ABS(deltax) >= ABS(deltay)) ? ABS(deltax) : ABS(deltay);
	deltax = deltax / step;
	deltay = deltay / step;
	n = 1;
	while (n <= step)
	{
		color = ft_get_color(p->color1, p->color2, step, n);
		if ((int)p->x1 <= WIDHT && (int)p->x1 >= 0 \
			&& (int)p->y1 <= WIDHT && (int)p->y1 >= 0)
			p->draw[(int)p->x1 + (int)p->y1 * WIDHT] = color;
		p->x1 = p->x1 + deltax;
		p->y1 = p->y1 + deltay;
		n += 1;
	}
}

void	ft_drawing_width_line(t_fdf *p, double x0, double y0)
{
	int	n;
	int	m;

	m = 0;
	while (m < p->hight)
	{
		n = 0;
		while (n < (p->width - 1))
		{
			p->x1 = x0 + p->shift * cos(p->angle) * n;
			p->y1 = y0 - p->shift * sin(p->angle) * n - \
					p->coords[m * p->width + n] * p->hgt;
			p->color1 = ft_get_point_colors(p, n, m);
			p->x2 = x0 + p->shift * cos(p->angle) * (n + 1);
			p->y2 = y0 - p->shift * sin(p->angle) * (n + 1) - \
					p->coords[m * p->width + n + 1] * p->hgt;
			p->color2 = ft_get_point_colors(p, n + 1, m);
			ft_drawing_line(p);
			n += 1;
		}
		m += 1;
		x0 += p->shift * cos(p->angle);
		y0 += p->shift * sin(p->angle);
	}
}

void	ft_drawing_hight_line(t_fdf *p, double x0, double y0)
{
	int	n;
	int	m;

	n = 0;
	while (n < p->width)
	{
		m = 0;
		while (m < (p->hight - 1))
		{
			p->x1 = x0 + p->shift * cos(p->angle) * m;
			p->y1 = y0 + p->shift * sin(p->angle) * m - \
					p->coords[p->width * m + n] * p->hgt;
			p->color1 = ft_get_point_colors(p, n, m);
			p->x2 = x0 + p->shift * cos(p->angle) * (m + 1);
			p->y2 = y0 + p->shift * sin(p->angle) * (m + 1) \
					- p->coords[p->width * (m + 1) + n] * p->hgt;
			p->color2 = ft_get_point_colors(p, n, m + 1);
			ft_drawing_line(p);
			m += 1;
		}
		n += 1;
		x0 += p->shift * cos(p->angle);
		y0 -= p->shift * sin(p->angle);
	}
}

void	ft_drawing_fon(t_fdf *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDHT)
		{
			p->draw[x + y * WIDHT] = 0x8B8B83;
			x += 1;
		}
		y += 1;
	}
}

void	ft_drawing_iso(t_fdf *p)
{
	double	x0;
	double	y0;
	int		n;

	x0 = p->x0;
	y0 = p->y0;
	ft_bzero(p->draw, WIDHT * HIGHT * 4);
	ft_drawing_fon(p);
	ft_drawing_width_line(p, x0, y0);
	ft_drawing_hight_line(p, x0, y0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, p->zoom);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, p->offset);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, p->height);
}
