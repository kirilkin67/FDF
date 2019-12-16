/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:18:18 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/12 17:18:54 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_light(int start, int end, double percent)
{
	return ((int)(start * (1 - percent) + end * percent));
}

int			ft_get_color_2(int z_max, int n)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	percent = (z_max == 0) ? 1 : ((double)n / (double)z_max);
	red = get_light((COLOR1 >> 16) & 0xFF, (COLOR2 >> 16) & 0xFF, percent);
	green = get_light((COLOR1 >> 8) & 0xFF, (COLOR2 >> 8) & 0xFF, percent);
	blue = get_light(COLOR1 & 0xFF, COLOR2 & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
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
		color = ft_get_color_2(p->z_max, p->coords[m * p->width + n]);
	else
		color = p->colors[m * p->width + n];
	return (color);
}
