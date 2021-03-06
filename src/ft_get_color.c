/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:18:18 by wrhett            #+#    #+#             */
/*   Updated: 2020/06/24 17:25:04 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_light(int start, int end, double percent)
{
	return ((int)(start * (1 - percent) + end * percent));
}

int			ft_get_color(int color1, int color2, int step, int n)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (color1 == color2)
		return (color1);
	percent = (step == 0) ? 1.0 : ((double)n / (double)step);
	red = get_light((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, percent);
	green = get_light((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, percent);
	blue = get_light(color1 & 0xFF, color2 & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

int			ft_get_point_colors(t_fdf *p, int n, int m)
{
	int	color;

	if (p->colors[m * p->width + n] == -1)
	{
		if (p->coords[m * p->width + n] < 0)
			color =
	ft_get_color(COLOR_BLL, COLOR_BL, p->z_min, p->coords[m * p->width + n]);
		else
			color =
	ft_get_color(COLOR_GR, COLOR_WH, p->z_max, p->coords[m * p->width + n]);
	}
	else
		color = p->colors[m * p->width + n];
	return (color);
}

void		ft_drawing_fon(t_fdf *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < HIGHT)
	{
		x = 0;
		while (x < WIDHT)
		{
			p->draw[x + y * WIDHT] = COLOR_FON;
			x += 1;
		}
		y += 1;
	}
}
