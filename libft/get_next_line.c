/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:32:51 by wrhett            #+#    #+#             */
/*   Updated: 2019/10/08 15:31:28 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 90
#define MAX_FD 4096

static size_t	ft_lenchr(char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			return (index);
		index += 1;
	}
	return (0);
}

static char		*get_next_line_read(const int fd, char *str)
{
	char		bufer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		ret;

	if (str == NULL)
		str = ft_strnew(0);
	while (ft_strchr(str, '\n') == NULL)
	{
		ret = read(fd, bufer, BUFF_SIZE);
		if (ret == 0)
			return (str);
		if (ret == -1)
			return (NULL);
		bufer[ret] = '\0';
		tmp = ft_strjoin(str, bufer);
		ft_strdel(&str);
		str = tmp;
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char *tab[MAX_FD];
	char		*str;
	char		*tmp;

	if (fd < 0 || fd > (MAX_FD - 1) || line == NULL || BUFF_SIZE < 1)
		return (-1);
	str = get_next_line_read(fd, tab[fd]);
	if (str == NULL)
		return (-1);
	if (ft_strchr(str, '\n') != NULL)
	{
		*line = ft_strsub(str, 0, ft_lenchr(str));
		tmp = ft_strdup(ft_strchr(str, '\n') + 1);
		ft_strdel(&str);
		tab[fd] = tmp;
		return (1);
	}
	if (*str != '\0')
	{
		*line = str;
		tab[fd] = ft_strnew(0);
		return (1);
	}
	return (0);
}
