/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:08:46 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/15 10:47:19 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	const char	*find;
	const char	*tmp;

	if (*to_find == '\0')
		return ((char *)str);
	find = to_find;
	while (*str != '\0')
	{
		tmp = str;
		while (*find == *tmp)
		{
			if (*(find + 1) == '\0')
				return ((char *)str);
			find += 1;
			tmp += 1;
		}
		find = to_find;
		str += 1;
	}
	return (NULL);
}
