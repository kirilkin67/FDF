/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:55 by wrhett            #+#    #+#             */
/*   Updated: 2020/05/31 22:52:44 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	min_shift(t_fdf *p)
{
	double	min_shift;

	min_shift = (double)WIDHT / (p->width + p->hight + 2) / cos(p->angle);
	if (min_shift * (p->width + p->hight - 2) * sin(p->angle) >= (double)HIGHT)
		min_shift = (double)HIGHT / (p->width + p->hight + 2) / sin(p->angle);
	if (min_shift < 1)
		min_shift = 1;
	return (min_shift);
}

void	ft_parametr_iso(t_fdf *p)
{
	p->flag = 0;
	p->angle_x = -ANGLE1;
	p->angle_y = ANGLE;
	p->angle_z = -ANGLE;
	p->angle = ANGLE;
	p->shift = min_shift(p);
	p->x0 = (double)WIDHT / 2;
	p->y0 = (double)HIGHT / 2;
	if (p->z_range != 0)
		p->hgt = ABS(((double)HIGHT - (p->width + p->hight) * p->shift
			* sin(p->angle)) / p->z_range);
}
