/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:56:28 by wrhett            #+#    #+#             */
/*   Updated: 2020/06/26 11:21:58 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_exit(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}

void		ft_operation(t_fdf *p)
{
	mlx_hook(p->win_ptr, 2, (1L << 0), key_press, p);
	mlx_hook(p->win_ptr, 17, 0, close_endian, p);
	mlx_hook(p->win_ptr, 4, (1L << 2), mouse_press, p);
	mlx_hook(p->win_ptr, 5, (1L << 3), mouse_release, p);
	mlx_hook(p->win_ptr, 6, (1L << 6), mouse_movement, p);
	mlx_hook(p->win_ptr, 12, (1L << 15), expose_hook, p);
}

static void	ft_initialize_mlx(t_fdf *p)
{
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDHT, HIGHT, "Fdf ISO");
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDHT, HIGHT);
	p->draw = \
	(int *)mlx_get_data_addr(p->img_ptr, &p->bpp, &p->size_line, &p->endian);
	ft_operation(p);
	ft_parametr_iso(p);
	ft_drawing_iso_obl(p);
	mlx_loop(p->mlx_ptr);
}

static void	copy_map_data(t_fdf *p, t_map *map)
{
	p->width = map->width;
	p->hight = map->height;
	p->coords = map->coords_arr;
	p->colors = map->colors_arr;
	p->z_min = map->z_min;
	p->z_max = map->z_max;
	p->z_range = map->z_range;
	p->mouse_key = -3;
}

int			main(int argc, char **argv)
{
	int			fd;
	t_fdf		p;
	t_map		*map;

	map = NULL;
	errno = 0;
	if (argc == 2)
	{
		map = ft_map_init();
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_exit(ERR_MAP);
		if (ft_read_map_prev(fd, map) == -1)
			ft_exit(ERR_MAP_READING);
		close(fd);
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_exit(ERR_MAP);
		if (ft_read_map_2(fd, map) == -1)
			ft_exit(ERR_MAP_READING);
		close(fd);
	}
	else
		ft_exit(ERR_USAGE);
	copy_map_data(&p, map);
	ft_initialize_mlx(&p);
	return (0);
}
