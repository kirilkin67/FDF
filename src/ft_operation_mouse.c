/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:03:40 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/18 19:08:09 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_endian(void *param)
{
	(void)param;
	exit(0);
}

void	zoom(int key, t_fdf *p)
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

int		mouse_press(int button, int x, int y, void *param)
{
	t_fdf *p;

	p = (t_fdf *)param;
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
		zoom(button, p);
	else if (button == 1)
		p->mouse_key = 1;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_fdf *p;

	(void)x;
	(void)y;
	(void)button;
	p = (t_fdf *)param;
	p->mouse_key = -1;
	return (0);
}

int		mouse_movement(int x, int y, void *param)
{
	t_fdf	*p;
	int		x1;
	int		y1;

	p = (t_fdf *)param;
	x1 = p->mouse_x;
	y1 = p->mouse_y;
	p->mouse_x = x;
	p->mouse_y = y;
	if (p->mouse_key == 1)
	{
		p->x0 += (x - x1);
		p->y0 += (y - y1);
		if (p->flag == 0 && p->mouse_key == 1)
			ft_drawing_iso(p);
		if (p->flag == 1 && p->mouse_key == 1)
			ft_drawing_iso_obl(p);
	}
	return (0);
}
