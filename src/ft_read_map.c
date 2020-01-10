/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:43:44 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/05 17:59:38 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	coord_to_arr(int z, int color, t_map *map)
{
	static ssize_t	i;

	if (!map->coords_arr)
		ft_map_init_2(map);
	map->coords_arr[i] = z;
	map->colors_arr[i] = color;
	if (z > map->z_max)
		map->z_max = z;
	if (z < map->z_min)
		map->z_min = z;
	i++;
	map->z_range = map->z_max - map->z_min;
}

static void	new_coord_2(char *str, t_map *map)
{
	char		**parts;
	int			z;
	int			color;

	if (!(parts = ft_strsplit(str, ',')))
		ft_exit(ERR_MAP_READING);
	if (!ft_isnumber(parts[0], 10))
		ft_exit(ERR_MAP_READING);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		ft_exit(ERR_MAP_READING);
	z = ft_atoi(parts[0]);
	color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord_to_arr(z, color, map);
	free(parts[1]);
	free(parts[0]);
	free(parts);
	free(str);
}

static int	how_many_words(char const *str, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i += 1;
		if (str[i] != '\0')
			n += 1;
		while (str[i] != c && str[i] != '\0')
			i += 1;
	}
	return (n);
}

int			ft_read_map_prev(const int fd, t_map *map)
{
	char	*line;
	int		result;
	int		words;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(words = how_many_words(line, ' ')))
			ft_exit(ERR_MAP_READING);
		if (map->height == 0)
			map->width = words;
		else if (map->width != words)
			ft_exit(ERR_FILE);
		map->height += 1;
		ft_strdel(&line);
	}
	return (result);
}

int			ft_read_map_2(const int fd, t_map *map)
{
	char	*line;
	int		result;
	char	**line_coord;
	char	**tmp;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(line_coord = ft_strsplit(line, ' ')))
			ft_exit(ERR_MAP_READING);
		ft_strdel(&line);
		tmp = line_coord;
		while (*line_coord)
			new_coord_2(*(line_coord++), map);
		free(tmp);
	}
	return (result);
}
