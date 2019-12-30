#include "../includes/fdf.h"

static void	zoom_x_y_plus(int key, t_fdf *p)
{
	if (p->shift > KZ && p->flag == 0)
	{
		if (key == 4 && p->mouse_x < WIDHT / 2)
		{
			p->x0 -= (KZ_MAX * (p->width - 1) * cos(ANGLE) / 2);
			if (p->mouse_y < HIGHT /2)
				p->y0 += (KZ_MAX * (p->hight - 1) * sin(ANGLE) / 2);
			if (p->mouse_y > HIGHT /2)
				p->y0 -= (KZ_MAX * (p->width - 1) * sin(ANGLE) / 2);
		}
		if (key == 4 && p->mouse_x > WIDHT / 2)
		{
			if (p->mouse_y < HIGHT /2)
			{
				p->x0 -= (KZ_MAX * (p->width + p->hight - 2) * cos(ANGLE));
				// p->y0 -= (KZ_MAX * (p->width - 1) * sin(ANGLE));
			}
			if (p->mouse_y > HIGHT /2)
			{
				p->x0 -= (KZ_MAX * (p->hight - 1) * cos(ANGLE));
				p->y0 -= (KZ_MAX * (p->hight - 1) * sin(ANGLE));
			}
		}
	}
	else if (p->shift < KZ && p->flag == 0)
		p->x0 -= (KZ_MIN * (p->width + p->hight - 2) * cos(ANGLE) / 2);
}

static void	zoom_x_y_minus(int key, t_fdf *p)
{
	if (p->shift > KZ && p->flag == 0)
	{
		if (key == 5 && p->mouse_x < WIDHT / 2)
		{
			p->x0 += (KZ_MAX * (p->width - 1) * cos(ANGLE) / 2);
			if (p->mouse_y < HIGHT /2)
				p->y0 -= (KZ_MAX * (p->hight - 1) * sin(ANGLE) / 2);
			if (p->mouse_y > HIGHT /2)
				p->y0 += (KZ_MAX * (p->width - 1) * sin(ANGLE) / 2);
		}
		if (key == 5 && p->mouse_x > WIDHT / 2)
		{
			if (p->mouse_y < HIGHT /2)
			{
				p->x0 += (KZ_MAX * (p->hight - 1) * cos(ANGLE));
				p->y0 -= (KZ_MAX * (p->width - 1) * sin(ANGLE) / 2);
			}
			if (p->mouse_y > HIGHT /2)
			{
				p->x0 += (KZ_MAX * (p->width - 1) * cos(ANGLE));
				p->y0 += (KZ_MAX * (p->hight - 1) * sin(ANGLE));
			}
		}
		// if (key == 27 || (key == 5 && p->mouse_x < WIDHT / 2))
		// 	p->x0 += (KZ_MAX * (p->width + p->hight - 2) * cos(ANGLE) / 2);
		// if (key == 5 && p->mouse_x > WIDHT / 2)
		// 	p->x0 += 0;
	}
	else if (p->shift < KZ && p->flag == 0)
		p->x0 += (KZ_MIN * (p->width + p->hight - 2) * cos(ANGLE) / 2);
}

void	zoom_mouse(int key, t_fdf *p)
{
	if (key == 4 && p->shift < WIDHT)
	{
			p->shift = (p->shift > KZ) ? p->shift + KZ_MAX : p->shift + KZ_MIN;
			p->hgt = (p->shift > KZ) ? p->hgt * (1 + KZ_MAX / p->shift) : \
			p->hgt * (1 + KZ_MIN / p->shift);
			zoom_x_y_plus(key, p);
	}
	else if (key == 5)
	{
		p->shift = (p->shift > KZ) ? p->shift - KZ_MAX : p->shift - KZ_MIN;
		if (p->shift > 1)
		{
			p->hgt = (p->shift > KZ) ? p->hgt * (1 - KZ_MAX / p->shift) : \
			p->hgt * (1 - KZ_MIN / p->shift);
			p->x0 = (p->shift > KZ) ? p->x0 + KZ_MAX : p->x0 + KZ_MIN;
			zoom_x_y_minus(key, p);
		}
		else if (p->shift < 1)
			p->hgt *= 1;
	}
	if (p->shift < 1)
		p->shift = 1;
	if (p->flag == 1)
		p->x0 = (WIDHT - p->shift * (p->width - 1 + (p->hight - 1) * sin(p->angle))) / 2;
	// p->x0 = (p->flag == 0) ? (WIDHT - p->shift * (p->width + p->hight - 2) * \
	// cos(p->angle)) / 2 : (WIDHT - p->shift * (p->width - 1 + (p->hight - 1) * \
	// sin(p->angle))) / 2;
	p->flag == 0 ? ft_drawing_iso(p) : ft_drawing_iso_obl(p);
}