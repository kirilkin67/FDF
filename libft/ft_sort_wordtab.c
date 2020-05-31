/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:11:23 by wrhett            #+#    #+#             */
/*   Updated: 2020/05/31 18:30:50 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_sort_wordtab(char **tab)
{
	size_t n;
	size_t index;

	index = 0;
	while (*(tab + index) != NULL)
		index += 1;
	index -= 1;
	while (index > 0)
	{
		n = 0;
		while (n != index)
		{
			if (ft_strcmp(tab[n], tab[n + 1]) > 0)
				ft_swap_tab((tab + n), (tab + n + 1));
			n += 1;
		}
		index -= 1;
	}
}
