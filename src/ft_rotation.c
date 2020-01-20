/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:07:17 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/20 18:46:29 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	point_height(t_fdf *p, int x, int y)
{
	double z;

	z = p->coords[p->width * y + x] * p->hgt;
	return (z);
}

void	ft_rotation_dot(t_fdf *p, t_dot *dot)
{
	int x;
	int y;

	y = dot->y;
	dot->y = y * cos(p->angle_x) + dot->z * sin(p->angle_x);
	dot->z = -y * sin(p->angle_x) + dot->z * cos(p->angle_x);
	x = dot->x;
	dot->x = x * cos(p->angle_y) + dot->z * sin(p->angle_y);
	dot->z = -x * sin(p->angle_y) + dot->z * cos(p->angle_y);
	x = dot->x;
	dot->x = x * cos(p->angle_z) - dot->y * sin(p->angle_z);
	dot->y = x * sin(p->angle_z) + dot->y * cos(p->angle_z);
	dot->x = p->x0 + dot->x;
	dot->y = p->y0 + dot->y;
}

void	ft_rotation(t_fdf *p)
{
	t_dot	dot1;
	t_dot	dot2;

	dot1.y = p->y1;
	dot2.y = p->y2;
	p->y1 = dot1.y * cos(p->angle_x) + p->z1 * sin(p->angle_x);
	p->z1 = -dot1.y * sin(p->angle_x) + p->z1 * cos(p->angle_x);
	p->y2 = dot2.y * cos(p->angle_x) + p->z2 * sin(p->angle_x);
	p->z2 = -dot2.y * sin(p->angle_x) + p->z2 * cos(p->angle_x);
	dot1.x = p->x1;
	dot2.x = p->x2;
	p->x1 = dot1.x * cos(p->angle_y) + p->z1 * sin(p->angle_y);
	p->z1 = -dot1.x * sin(p->angle_y) + p->z1 * cos(p->angle_y);
	p->x2 = dot2.x * cos(p->angle_y) + p->z2 * sin(p->angle_y);
	p->z2 = -dot2.x * sin(p->angle_y) + p->z2 * cos(p->angle_y);
	dot1.x = p->x1;
	dot2.x = p->x2;
	p->x1 = p->x0 + (dot1.x * cos(p->angle_z) - p->y1 * sin(p->angle_z));
	p->y1 = p->y0 + (dot1.x * sin(p->angle_z) + p->y1 * cos(p->angle_z));
	p->x2 = p->x0 + (dot2.x * cos(p->angle_z) - p->y2 * sin(p->angle_z));
	p->y2 = p->y0 + (dot2.x * sin(p->angle_z) + p->y2 * cos(p->angle_z));
}
