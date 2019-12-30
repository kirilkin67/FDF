/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:35:26 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/30 14:09:28 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Function Digital Differential Analyzer on the double in header*/

// void		ft_drawing_line(t_fdf *p) 
// {
// 	double	deltax;
// 	double	deltay;
// 	double	step;
// 	int		color;
// 	int		n;

// 	deltax = p->x2 - p->x1;
// 	deltay = p->y2 - p->y1;
// 	step = (ABS(deltax) >= ABS(deltay)) ? ABS(deltax) : ABS(deltay);
// 	deltax = deltax / step;
// 	deltay = deltay / step;
// 	n = 0;
// 	while (n <= step)
// 	{
// 		color = ft_get_color(p->color1, p->color2, step, n);
// 		if ((int)p->x1 >= 0 && (int)p->x1 <= (WIDHT - 2) \
// 			&& (int)p->y1 >= 0 && (int)p->y1 <= (HIGHT - 2))
// 			p->draw[(int)round(p->x1) + (int)round(p->y1) * WIDHT] = color;
// 		p->x1 = p->x1 + deltax;
// 		p->y1 = p->y1 + deltay;
// 		n += 1;
// 	}
// }
/* Function Bresenham's line algorithm on the int*/

// void	ft_drawing_line(t_fdf *p)
// {
// 	int	deltax;
// 	int	deltay;
// 	int	sign_x;
// 	int	sign_y;
// 	int	error;
// 	int	error2;
// 	int step;
// 	int	color;
// 	int	n;

// 	deltax = ABS(((int)p->x2 - (int)p->x1));
// 	deltay = ABS(((int)p->y2 - (int)p->y1));
// 	step = (deltax >= deltay) ? deltax : deltay;
// 	sign_x = (int)p->x1 < (int)p->x2 ? 1 : -1;
// 	sign_y = (int)p->y1 < (int)p->y2 ? 1 : -1;
// 	error = deltax - deltay;
// 	n = 0;
// 	while (p->x1 <= p->x2 || p->y1 <= p->y2) //(n <= step)
// 	{
// 		color = ft_get_color(p->color1, p->color2, step, n);
// 		if ((int)p->x1 >= 0 && (int)p->x1 <= (WIDHT - 1) \
// 			&& (int)p->y1 >= 0 && (int)p->y1 <= (HIGHT - 1))
// 			p->draw[(int)p->x1 + (int)p->y1 * WIDHT] = color;
// 		error2 = error * 2;
// 		if (error2 > -deltay) 
// 		{
// 			error -= deltay;
// 			p->x1 += sign_x;
// 		}
// 		if (error2 < deltax) 
// 		{
// 			error += deltax;
// 			p->y1 += sign_y;
// 		}
// 		n += 1;
// 	}
// }


void	ft_drawing_line(t_fdf *p)
{
	p->deltax = ABS((p->x2 - p->x1));
	p->deltay = ABS((p->y2 - p->y1));
	p->step = (p->deltax >= p->deltay) ? p->deltax : p->deltay;
	p->sign_x = p->x1 < p->x2 ? 1 : -1;
	p->sign_y = p->y1 < p->y2 ? 1 : -1;
	p->error = p->deltax - p->deltay;
	p->n = 0;
	while (p->n++ <= p->step) //(p->x1 != p->x2 || p->y1 != p->y2)
	{
		if (p->x1 >= 0 && p->x1 <= WIDHT - 1 && p->y1 >= 0 && p->y1 <= HIGHT - 1)
			p->draw[p->x1 + p->y1 * WIDHT] = \
			ft_get_color(p->color1, p->color2, p->step, p->n);
		p->error2 = p->error * 2;
		if (p->error2 > -p->deltay)
		{
			p->error -= p->deltay;
			p->x1 += p->sign_x;
		}
		if (p->error2 < p->deltax)
		{
			p->error += p->deltax;
			p->y1 += p->sign_y;
		}
		// p->n++;
	}
}
