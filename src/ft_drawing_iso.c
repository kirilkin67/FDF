/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:55 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/20 18:44:28 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		min_shift(t_fdf *p)
{
	double	min_shift;

	min_shift = WIDHT / (p->width + p->hight + 2) / cos(p->angle);
	if (min_shift * (p->width + p->hight - 2) * sin(p->angle) >= HIGHT)
		min_shift = HIGHT / (p->width + p->hight + 2) / sin(p->angle);
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
	p->x0 = WIDHT / 2;
	p->y0 = HIGHT / 2;
	// p->x0 = (WIDHT - (p->width + p->hight - 2) * p->shift * cos(p->angle)) / 2;
	if (p->z_range != 0)
		p->hgt = ABS((HIGHT - (p->width + p->hight - 2) * p->shift * \
				sin(p->angle))/ p->z_range);
	// if (p->z_range == 0)
		// p->y0 = (HIGHT + ((p->width - p->hight) * p->shift * sin(p->angle))) / 2;
	//else
		// p->y0 = (p->width - 1) * p->shift * sin(p->angle) + p->hgt * p->z_max;
}

// static void	ft_drawing_width_line(t_fdf *p)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < p->hight)
// 	{
// 		x = 0;
// 		while (x < (p->width - 1))
// 		{
// 			p->z1 = point_height(p, x, y);
// 			p->x1 = p->shift * cos(p->angle) * (x + y);
// 			p->y1 = p->shift * sin(p->angle) * (x - y);
// 			p->color1 = ft_get_point_colors(p, x, y);
// 			p->z2 = point_height(p, x + 1, y);
// 			p->x2 = p->shift * cos(p->angle) * (x + y + 1);
// 			p->y2 = p->shift * sin(p->angle) * (x - y + 1);
// 			p->color2 = ft_get_point_colors(p, x + 1, y);
// 			ft_rotation(p);
// 			ft_drawing_line(p);
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// }

// static void	ft_drawing_hight_line(t_fdf *p)
// {
// 	int	x;
// 	int	y;

// 	x = p->width - 1;
// 	while (x >= 0)
// 	{
// 		y = 0;
// 		while (y < (p->hight - 1))
// 		{
// 			p->z1 = point_height(p, x, y);
// 			p->x1 = p->shift * cos(p->angle) * (x + y);
// 			p->y1 = p->shift * sin(p->angle) * (x - y);
// 			p->color1 = ft_get_point_colors(p, x, y);
// 			p->z2 = point_height(p, x, y + 1);
// 			p->x2 = p->shift * cos(p->angle) * (x + y + 1);
// 			p->y2 = p->shift * sin(p->angle) * (x - (y + 1));
// 			p->color2 = ft_get_point_colors(p, x, y + 1);
// 			ft_rotation(p);
// 			ft_drawing_line(p);
// 			y += 1;
// 		}
// 		x -= 1;
// 	}
// }

// void		ft_drawing_iso(t_fdf *p)
// {
// 	ft_bzero(p->draw, WIDHT * HIGHT * 4);
// 	ft_drawing_hight_line(p);
// 	ft_drawing_width_line(p);
// 	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
// 	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, STR1);
// 	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR2);
// 	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR3);
// 	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 80, 0xFFFFFF, STR4);
// 	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 100, 0xFFFFFF, STR5);
// }
