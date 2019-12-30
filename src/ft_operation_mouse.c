/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:03:40 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/30 15:46:02 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_endian(void *param)
{
	(void)param;
	exit(0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fdf *p;

	p = (t_fdf *)param;
	if (button == 4 || button == 5) // колесико scrol UP +, scroll DOWN -
	{
		p->mouse_x = x;
		p->mouse_y = y;
		zoom_mouse(button, p);
	}
	else if (button == 1 && (y >= 0 && y <= (HIGHT - 1)) && (x >= 0 && y <= (WIDHT - 1)))
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
	p->mouse_key = -3;
	// p->mouse_x = x;
	// p->mouse_y = y;
	
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
