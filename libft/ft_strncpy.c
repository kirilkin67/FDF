/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:32:41 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/18 15:10:40 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t index;

	index = 0;
	while (index < n && *src)
	{
		dest[index] = *src;
		index += 1;
		src += 1;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index += 1;
	}
	return (dest);
}
