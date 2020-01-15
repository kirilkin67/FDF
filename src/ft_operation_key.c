/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:17:57 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/15 19:57:02 by wrhett           ###   ########.fr       */
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
		p->x0 -= 10;
	else if (key == 124)
		p->x0 += 10;
	else if (key == 125)
		p->y0 += 10;
	else if (key == 126)
		p->y0 -= 10;
	if (p->x0 < -(p->width + p->hight - 2) * p->shift * cos(p->angle))
		p->x0 = (WIDHT - 1);
	if (p->x0 > (WIDHT - 1))
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

static void	coordinate_x_start(t_fdf *p, int key)
{
	double k_zoom;
	
	k_zoom = (p->shift > KZ) ? KZ_MAX : KZ_MIN;
	if (key == 24) 
		k_zoom *= -1;
	if (p->flag == 0)
		p->x0 += k_zoom * (p->width + p->hight - 2) * cos(p->angle) * 0.5;
	if (p->flag == 1)
		// p->x0 += k_zoom * (p->width - 1 + (p->hight - 1) * sin(p->angle)) * 0.5;
		p->x0 += k_zoom * (p->width - 1) * 0.5;
}

void	zoom_key(int key, t_fdf *p)
{
	if (key == 24 && p->shift < WIDHT)
	{
		coordinate_x_start(p, key);
		p->shift = (p->shift > KZ) ? p->shift + KZ_MAX : p->shift + KZ_MIN;
		p->hgt = (p->shift > KZ) ? p->hgt * (1 + KZ_MAX / p->shift) : \
		p->hgt * (1 + KZ_MIN / p->shift);
	}
	else if (key == 27)
	{
		if (p->shift > 1)
		{
			coordinate_x_start(p, key);
			p->shift = (p->shift > KZ) ? p->shift - KZ_MAX : p->shift - KZ_MIN;
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

void	look(int key, t_fdf *p)
{
	if (key == NUM_KEY_8)
		p->angle_x += K_LOOK;
	else if (key == NUM_KEY_2)
		p->angle_x -= K_LOOK;
	else if (key == 83)
		p->angle_y -= K_LOOK;
	else if (key == 85)
		p->angle_y += K_LOOK;
	else if (key == NUM_KEY_4)
		p->angle_z += K_LOOK;
	else if (key == NUM_KEY_6)
		p->angle_z -= K_LOOK;
	// p->x0 = (p->flag == 0) ? (WIDHT - p->shift * (p->width + p->hight - 2) * \
	// cos(p->angle)) / 2 : (WIDHT - p->shift * (p->width - 1 + (p->hight - 1) * \
	// cos(p->angle))) / 2;
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
	if (key == 84 || key == 91 || key == NUM_KEY_4 || key == NUM_KEY_6 \
		|| key == 83 || key == 85)
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
