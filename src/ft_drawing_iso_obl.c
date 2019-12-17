#include "../includes/fdf.h"

double		min_shift_oblique(t_fdf *p)
{
	double	shift;

	shift = WIDHT / (p->width + p->hight * sin(p->angle));
	if ((shift * (p->hight - 1) * sin(p->angle) + p->z_max * shift) > HIGHT)
		shift = HIGHT / ((p->hight - 1) * sin(p->angle) + p->z_range + 2);
	return (shift);
}

static void	ft_drawing_width_line_obl(t_fdf *p, double x0, double y0)
{
	int	n;
	int	m;
	
	m = 0;
	while (m < p->hight)
	{
		n = 0;
		while ( n < (p->width - 1))
		{
			p->x1 = x0 + p->shift * n;
			p->y1 = y0 - p->coords[m * p->width + n] * p->hgt * cos(ANGLE1);
			p->color1 = ft_get_point_colors(p, n, m);
			p->x2 = x0 + p->shift * (n + 1);
			p->y2 = y0 - p->coords[m * p->width + n + 1] * p->hgt * cos(ANGLE1);
			p->color2 = ft_get_point_colors(p, n + 1, m);
			ft_drawing_line(p);
			n += 1;
		}
		m += 1;
		x0 += p->shift * cos(p->angle);
		y0 += p->shift * sin(p->angle);
	}
}

static void	ft_drawing_hight_line_obl(t_fdf *p, double x0, double y0)
{
	int	n;
	int	m;
	
	n = 0;
	while (n < p->width)
	{
		m = 0;
		while ( m < (p->hight - 1))
		{
			p->x1 = x0 + p->shift * cos(p->angle) * m;
			p->y1 = y0 + p->shift * sin(p->angle) * m - \
					p->coords[p->width * m + n] * p->hgt * cos(ANGLE1);
			p->color1 = ft_get_point_colors(p, n, m);
			p->x2 = x0 + p->shift * cos(p->angle) * (m + 1);
			p->y2 = y0 + p->shift * sin(p->angle) * (m + 1) \
					- p->coords[p->width * (m + 1) + n] * p->hgt * cos(ANGLE1);
			p->color2 = ft_get_point_colors(p, n, m + 1);
			ft_drawing_line(p);
			m += 1;
		}
		n += 1;
		x0 += p->shift;
	}
}

void	ft_drawing_iso_obl(t_fdf *p)
{
	double	x0;
	double	y0;
	
	x0 = p->x0;// Xo
	y0 = p->y0; // Yo
	ft_bzero(p->draw, WIDHT * HIGHT * 4);
	ft_drawing_width_line_obl(p, x0, y0);
	ft_drawing_hight_line_obl(p, x0, y0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 20, 0xFFFFFF, p->zoom);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 40, 0xFFFFFF, p->offset);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 20, 60, 0xFFFFFF, p->height);
}

// 0.78539816339745 - 45 град
// 1.570784 - 90