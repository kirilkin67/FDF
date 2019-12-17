/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:57 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/17 18:56:34 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			close_endian(void *param)
{
	(void)param;
	exit(0);
}

void		zoom(int key, t_fdf *p)
{
	if (key == 24 || key == 5)
	{
		p->shift += KZ;
		p->hgt *= (1 + KZ / p->shift);
	}
	else if (key == 27 || key == 4)
	{
		p->shift -= KZ;
		if (p->shift > 1)
			p->hgt *= (1 - KZ / p->shift);
		else if (p->shift < 1)
			p->hgt *= 1;
	}
	if (p->shift < 1)
		p->shift = 1;
	if (p->flag == 0)
		ft_drawing_iso(p);
	else if (p->flag == 1)
		ft_drawing_iso_obl(p);
}

static void	height(int key, t_fdf *p)
{
	if (key == 69)
		p->hgt += 0.5;
	else if (key == 78)
		p->hgt -= 0.5;
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

int			key_press(int key, void *param)
{
	t_fdf *p;

	p = (t_fdf *)param;
	if (key == 53)
		exit(0);
	if (key == 24 || key == 27)
		zoom(key, p);
	if (key == 69 || key == 78)
		height(key, p);
	if (key == 125 || key == 126 || key == 123 || key == 124)
		shift(key, p);
	if (key == 34)
	{
		p->flag = 0;
		p->angle = ANGLE;
		p->shift = min_shift(p);
		p->hgt = p->shift;
		p->x0 = (WIDHT - (p->width + p->hight - 2) * p->shift * cos(p->angle)) / 2;
		// p->y0 = HIGHT - p->hight* p->shift * sin(p->angle);
		p->y0 = p->width * p->shift * sin(p->angle) + p->z_max * p->shift;
		p->hgt = p->shift;
		if (p->hgt * p->z_range > HIGHT)
			p->hgt = ABS(HIGHT / p->z_range);
		ft_drawing_iso(p);
	}
	if (key == 31)
	{
		p->flag = 1;
		p->angle = ANGLE1;
		p->shift = min_shift_oblique(p);
		p->x0 = (WIDHT - p->shift * (p->width - 1 + (p->hight - 1) * sin(p->angle))) / 2;
		p->y0 = (p->z_max == 0) ? (HIGHT - p->hight * p->shift * sin(p->angle)) : p->z_max * p->shift;
		//p->y0 = p->hight * p->shift * sin(p->angle) + p->z_max * p->shift;
		// p->y0 = (HIGHT + p->z_max * p->shift - p->hight * p->shift * sin(p->angle)) /2;
		p->hgt = p->shift;
		if (p->hgt * p->z_range > HIGHT)
			p->hgt = ABS(HIGHT / p->z_range);
		ft_drawing_iso_obl(p);
	}
	return (0);
}
