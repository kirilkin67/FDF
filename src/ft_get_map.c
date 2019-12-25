/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:00:11 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/19 14:56:13 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*ft_map_init(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_exit(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = 0;
	map->z_max = 0;
	map->z_range = 0;
	return (map);
}

t_map	*ft_map_init_2(t_map *map)
{
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->coords_arr = (int *)ft_memalloc(arr_size)))
		ft_exit(ERR_CONV_TO_ARR);
	if (!(map->colors_arr = (int *)ft_memalloc(arr_size)))
		ft_exit(ERR_CONV_TO_ARR);
	return (map);
}
