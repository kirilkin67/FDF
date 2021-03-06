/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:35:26 by wrhett            #+#    #+#             */
/*   Updated: 2020/06/26 11:33:56 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Function Digital Differential Analyzer on the double in header
** void		ft_drawing_line(t_fdf *p)
**{
**	double	deltax;
**	double	deltay;
**	double	step;
**	int		color;
**	int		n;
**
**	deltax = p->x2 - p->x1;
**	deltay = p->y2 - p->y1;
**	step = (ABS(deltax) >= ABS(deltay)) ? ABS(deltax) : ABS(deltay);
**	deltax = deltax / step;
**	deltay = deltay / step;
**	n = 0;
**	while (n <= step)
**	{
**		color = ft_get_color(p->color1, p->color2, step, n);
**		if ((int)p->x1 >= 0 && (int)p->x1 <= (WIDHT - 2)
**			&& (int)p->y1 >= 0 && (int)p->y1 <= (HIGHT - 2))
**			p->draw[(int)round(p->x1) + (int)round(p->y1) * WIDHT] = color;
**		p->x1 = p->x1 + deltax;
**		p->y1 = p->y1 + deltay;
**		n += 1;
**	}
** }
*/

/*
** Function Bresenham's line algorithm on the int
**void	ft_drawing_line(t_fdf *p)
**{
**	int	deltax;
**	int	deltay;
**	int	sign_x;
**	int	sign_y;
**	int	error;
**	int	error2;
**	int step;
**	int	color;
**	int	n;
**
**	deltax = ABS(((int)p->x2 - (int)p->x1));
**	deltay = ABS(((int)p->y2 - (int)p->y1));
**	step = (deltax >= deltay) ? deltax : deltay;
**	sign_x = (int)p->x1 < (int)p->x2 ? 1 : -1;
**	sign_y = (int)p->y1 < (int)p->y2 ? 1 : -1;
**	error = deltax - deltay;
**	n = 0;
**	while (p->x1 <= p->x2 || p->y1 <= p->y2) //(n <= step)
**	{
**		color = ft_get_color(p->color1, p->color2, step, n);
**		if ((int)p->x1 >= 0 && (int)p->x1 <= (WIDHT - 1)
**			&& (int)p->y1 >= 0 && (int)p->y1 <= (HIGHT - 1))
**			p->draw[(int)p->x1 + (int)p->y1 * WIDHT] = color;
**		error2 = error * 2;
**		if (error2 > -deltay)
**		{
**			error -= deltay;
**			p->x1 += sign_x;
**		}
**		if (error2 < deltax)
**		{
**			error += deltax;
**			p->y1 += sign_y;
**		}
**		n += 1;
**	}
**}
*/

static void	drawing_data(t_fdf *p, t_draw *data)
{
	data->deltax = ABS((p->x2 - p->x1));
	data->deltay = ABS((p->y2 - p->y1));
	data->step = (data->deltax >= data->deltay) ? data->deltax : data->deltay;
	data->sign_x = p->x1 < p->x2 ? 1 : -1;
	data->sign_y = p->y1 < p->y2 ? 1 : -1;
	data->error = data->deltax - data->deltay;
}

void		ft_drawing_line(t_fdf *p)
{
	t_draw data;

	drawing_data(p, &data);
	data.n = 0;
	while (p->x1 != p->x2 || p->y1 != p->y2)
	{
		if (p->x1 >= 0 && p->x1 <= (WIDHT - 1) && p->y1 >= 0 && \
			p->y1 <= (HIGHT - 1))
			p->draw[p->x1 + p->y1 * WIDHT] = \
			ft_get_color(p->color1, p->color2, data.step, data.n);
		data.error2 = data.error * 2;
		if (data.error2 > -data.deltay)
		{
			data.error -= data.deltay;
			p->x1 += data.sign_x;
		}
		if (data.error2 < data.deltax)
		{
			data.error += data.deltax;
			p->y1 += data.sign_y;
		}
		data.n += 1;
	}
}

void		ft_drawing_line_dot(t_fdf *p, t_dot *dot1, t_dot *dot2)
{
	t_dot	tmp;
	double	deltax;
	double	deltay;
	double	step;
	int		n;

	deltax = dot2->x - dot1->x;
	deltay = dot2->y - dot1->y;
	step = (ABS(deltax) >= ABS(deltay)) ? ABS(deltax) : ABS(deltay);
	deltax = deltax / step;
	deltay = deltay / step;
	tmp.x = dot1->x;
	tmp.y = dot1->y;
	n = 0;
	while (n <= step)
	{
		tmp.color = ft_get_color(dot1->color, dot2->color, step, n);
		if ((int)round(tmp.x) >= 0 && (int)round(tmp.x) <= (WIDHT - 1) \
			&& (int)round(tmp.y) >= 0 && (int)round(tmp.y) <= (HIGHT - 1))
			p->draw[(int)round(tmp.x) + (int)round(tmp.y) * WIDHT] = tmp.color;
		tmp.x += deltax;
		tmp.y += deltay;
		n += 1;
	}
}

void		print_instructions(t_fdf *p)
{
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, STR1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, STR2);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, STR3);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 80, 0xFFFFFF, STR4);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 100, 0xFFFFFF, STR5);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 120, 0xFFFFFF, STR6);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 140, 0xFFFFFF, STR7);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 160, 0xFFFFFF, STR8);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 180, 0xFFFFFF, STR9);
}
