#include "../includes/fdf.h"

// static void	zoom(int key, t_fdf *p)
// {
// 	if (key == 24)
// 	{
// 		p->shift += 0.5;
// 		p->hgt = p->shift;
// 	}
// 	else if (key == 27)
// 	{
// 		p->shift -= 0.5;
// 		p->hgt = p->shift;
// 	}
// 	if (p->shift < 1)
// 		p->shift = 1;
// 	ft_drawing_iso(p);
// }

int			mouse_press(int button, int x, int y, void *param)
{
	t_fdf *p;

	p = (t_fdf *)param;
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
		zoom(button, p);
	return (0);
}
