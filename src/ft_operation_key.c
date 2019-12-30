/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:57 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/30 15:38:04 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	height(int key, t_fdf *p)
{
	if (key == 69)
		p->hgt = (p->shift > KZ) ? p->hgt + KH_MAX : p->hgt + KH_MIN;
	else if (key == 78)
		p->hgt = (p->shift > KZ) ? p->hgt - KH_MAX : p->hgt - KH_MIN;
	if (p->flag == 0)
		ft_drawing_iso(p);
	else if (p->flag == 1)
		ft_drawing_iso_obl(p);
}

static void	shift(int key, t_fdf *p)
{
	if (key == 123)
		p->x0 -= 5;
	else if (key == 124)
		p->x0 += 5;
	else if (key == 125)
		p->y0 += 5;
	else if (key == 126)
		p->y0 -= 5;
	if (p->x0 < -(p->width + p->hight - 2) * p->shift * cos(p->angle))
		p->x0 = WIDHT;
	if (p->x0 > WIDHT)
		p->x0 = -(p->width + p->hight - 2) * p->shift * cos(p->angle);
	if (p->y0 + p->hight * p->shift * sin(p->angle) < 1)
		p->y0 = HIGHT + p->width * p->shift * sin(p->angle);
	if (p->y0 - p->width * p->shift * sin(p->angle) > HIGHT)
		p->y0 = -p->hight * p->shift * sin(p->angle);
	if (p->flag == 0)
		ft_drawing_iso(p);
	else if (p->flag == 1)
		ft_drawing_iso_obl(p);
}

void	zoom_key(int key, t_fdf *p)
{
	if (key == 24 && p->shift < WIDHT)
	{
			p->shift = (p->shift > KZ) ? p->shift + KZ_MAX : p->shift + KZ_MIN;
			p->hgt = (p->shift > KZ) ? p->hgt * (1 + KZ_MAX / p->shift) : \
			p->hgt * (1 + KZ_MIN / p->shift);
	}
	else if (key == 27)
	{
		p->shift = (p->shift > KZ) ? p->shift - KZ_MAX : p->shift - KZ_MIN;
		if (p->shift > 1)
			p->hgt = (p->shift > KZ) ? p->hgt * (1 - KZ_MAX / p->shift) : \
			p->hgt * (1 - KZ_MIN / p->shift);
		else if (p->shift < 1)
			p->hgt *= 1;
	}
	if (p->shift < 1)
		p->shift = 1;
	p->x0 = (p->flag == 0) ? (WIDHT - p->shift * (p->width + p->hight - 2) * \
	cos(p->angle)) / 2 : (WIDHT - p->shift * (p->width - 1 + (p->hight - 1) * \
	sin(p->angle))) / 2;
	p->flag == 0 ? ft_drawing_iso(p) : ft_drawing_iso_obl(p);
}

void	look(int key, t_fdf *p)
{
	if (key == 6)
		p->k_look += K_LOOK;
	else if (key == 7)
		p->k_look -= K_LOOK;
	p->angle = ANGLE - p->k_look;
	p->x0 = (p->flag == 0) ? (WIDHT - p->shift * (p->width + p->hight - 2) * \
	cos(p->angle)) / 2 : (WIDHT - p->shift * (p->width - 1 + (p->hight - 1) * \
	cos(p->angle))) / 2;
	p->flag == 0 ? ft_drawing_iso(p) : ft_drawing_iso_obl(p);
}

int			key_press(int key, void *param)
{
	t_fdf *p;

	p = (t_fdf *)param;
	if (key == 53)
		exit(0);
	if (key == 24 || key == 27)
		zoom_key(key, p);
	if (key == 69 || key == 78)
		height(key, p);
	if (key == 125 || key == 126 || key == 123 || key == 124)
		shift(key, p);
	if (key == 6 || key == 7)
		look(key, p); 
	if (key == 34)
	{
		ft_parametr_iso(p);
		ft_drawing_iso(p);
	}
	if (key == 31)
	{
		ft_parametr_iso_obl(p);
		ft_drawing_iso_obl(p);
	}
	return (0);
}
