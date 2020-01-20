/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:57 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/20 18:15:27 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	height(int key, t_fdf *p)
{
	if (key == 69)
		p->hgt = (p->shift > KZ) ? p->hgt + KH_MAX : p->hgt + KH_MIN;
	else if (key == 78)
		p->hgt = (p->shift > KZ) ? p->hgt - KH_MAX : p->hgt - KH_MIN;
		ft_drawing_iso_obl(p);
}

static void	coordinate_x_y_shift(int flag, t_fdf *p)
{
	if (flag == 1)
	{
		if (p->x0 < (-(p->width - 1) * p->shift / 2))
			p->x0 = (WIDHT + (p->width - 1) * p->shift / 2);
		if (p->x0 > (WIDHT + (p->width - 1) * p->shift / 2))
			p->x0 = -(p->width - 1) * p->shift / 2;
		if (p->y0 < (-(p->hight - 1) * p->shift / 2))
			p->y0 = (HIGHT + (p->hight - 1) * p->shift / 2);
		if (p->y0 > (HIGHT + (p->hight - 1) * p->shift / 2))
			p->y0 = -(p->hight - 1) * p->shift / 2;
	}
	if (flag == 0)
	{
		if (p->x0 < -(p->width + p->hight - 2) * p->shift * cos(p->angle) / 2)
			p->x0 = WIDHT + (p->width + p->hight - 2) * p->shift * cos(p->angle) / 2;
		if (p->x0 > (WIDHT + (p->width + p->hight - 2) * p->shift * cos(p->angle) / 2))
			p->x0 = -(p->width + p->hight - 2) * p->shift * cos(p->angle) / 2;
		if (p->y0 < -(p->width + p->hight - 2) * p->shift * sin(p->angle) / 2)
			p->y0 = HIGHT + (p->width + p->hight - 2) * p->shift * sin(p->angle) / 2;
		if (p->y0 > (HIGHT + (p->width + p->hight - 2) * p->shift * sin(p->angle) / 2))
			p->y0 = -(p->width + p->hight - 2) * p->shift * sin(p->angle) / 2;
	}
}

static void	shift(int key, t_fdf *p)
{
	if (key == 123)
		p->x0 -= K_SHIFT;
	else if (key == 124)
		p->x0 += K_SHIFT;
	else if (key == 125)
		p->y0 += K_SHIFT;
	else if (key == 126)
		p->y0 -= K_SHIFT;
	if (p->flag == 1 || p->flag == 0)
		coordinate_x_y_shift(p->flag, p);
	ft_drawing_iso_obl(p);
}

void	look(int key, t_fdf *p)
{
	if (key == NUM_KEY_8)
		p->angle_x += K_ROT;
	else if (key == NUM_KEY_2)
		p->angle_x -= K_ROT;
	else if (key == 83)
		p->angle_y += K_ROT;
	else if (key == 85)
		p->angle_y -= K_ROT;
	else if (key == NUM_KEY_4)
		p->angle_z += K_ROT;
	else if (key == NUM_KEY_6)
		p->angle_z -= K_ROT;
	ft_drawing_iso_obl(p);
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
	if (key == 84 || key == 91 || key == NUM_KEY_4 || key == NUM_KEY_6 \
		|| key == 83 || key == 85)
		look(key, p); 
	if (key == 34)
		ft_parametr_iso(p);
	if (key == 31)
		ft_parametr_iso_obl(p);
	ft_drawing_iso_obl(p);
	return (0);
}
