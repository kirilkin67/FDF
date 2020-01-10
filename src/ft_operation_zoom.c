/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_zoom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:58:24 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/10 18:05:23 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	alfa_x_y(t_fdf *p)
{
	if (p->flag == 0)
	{
		p->alfa_x = (p->mouse_x - p->x0) / \
		((p->width + p->hight - 2) * p->shift * cos(p->angle));
		p->alfa_y = (p->mouse_y - p->y0) / \
		((p->width + p->hight - 2) * p->shift * sin(p->angle));
	}
	if (p->flag == 1)
	{
		p->alfa_x = (p->mouse_x - p->x0) / \
		((p->width - 1 + (p->hight - 1) * cos(p->angle)) * p->shift);
		p->alfa_y = (p->mouse_y - p->y0) / \
		((p->hight - 1) * p->shift * sin(p->angle));
	}
}

static void	zoom_x_y_plus(t_fdf *p)
{
	double k_zoom;

	k_zoom = (p->shift > KZ) ? KZ_MAX : KZ_MIN;
	alfa_x_y(p);
	if (p->flag == 0)
	{
		p->x0 -= k_zoom * (p->width + p->hight - 2) * cos(p->angle) * p->alfa_x;
		p->y0 -= k_zoom * (p->width + p->hight - 2) * sin(p->angle) * p->alfa_y;
	}
	if (p->flag == 1)
	{
		p->x0 -= k_zoom * (p->width - 1 + (p->hight - 1) * cos(p->angle)) * \
					p->alfa_x;
		p->y0 -= k_zoom * (p->hight - 1) * sin(p->angle) * p->alfa_y;
	}
}

static void	zoom_x_y_minus(t_fdf *p)
{
	double k_zoom;

	k_zoom = (p->shift > KZ) ? KZ_MAX : KZ_MIN;
	alfa_x_y(p);
	if (p->flag == 0 && p->shift > 1)
	{
		p->x0 += k_zoom * (p->width + p->hight - 2) * cos(p->angle) * p->alfa_x;
		p->y0 += k_zoom * (p->width + p->hight - 2) * sin(p->angle) * p->alfa_y;
	}
	if (p->flag == 1 && p->shift > 1)
	{
		p->x0 += k_zoom * (p->width - 1 + (p->hight - 1) * cos(p->angle)) * \
					p->alfa_x;
		p->y0 += k_zoom * (p->hight - 1) * sin(p->angle) * p->alfa_y; 
	}
}


void	zoom_mouse(int key, t_fdf *p)
{
	if (key == 4 && p->shift < WIDHT)
	{
		zoom_x_y_plus(p);
		p->shift = (p->shift > KZ) ? p->shift + KZ_MAX : p->shift + KZ_MIN;
		p->hgt = (p->shift > KZ) ? p->hgt * (1 + KZ_MAX / p->shift) : \
		p->hgt * (1 + KZ_MIN / p->shift);
	}
	else if (key == 5)
	{
		zoom_x_y_minus(p);
		p->shift = (p->shift > KZ) ? p->shift - KZ_MAX : p->shift - KZ_MIN;
		if (p->shift > 1)
		{
			p->hgt = (p->shift > KZ) ? p->hgt * (1 - KZ_MAX / p->shift) : \
			p->hgt * (1 - KZ_MIN / p->shift);
		}
		else if (p->shift < 1)
			p->hgt *= 1;
	}
	if (p->shift < 1)
		p->shift = 1;
	p->flag == 0 ? ft_drawing_iso(p) : ft_drawing_iso_obl(p);
}
