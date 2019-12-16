/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:57 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/16 15:49:36 by wrhett           ###   ########.fr       */
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
	ft_drawing_iso(p);
}

static void	height(int key, t_fdf *p)
{
	if (key == 69)
		p->hgt += KH;
	else if (key == 78)
		p->hgt -= KH;
	ft_drawing_iso(p);
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
	ft_drawing_iso(p);
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
		p->angle = ANGLE;
		ft_drawing_iso(p);
	}
	return (0);
}
