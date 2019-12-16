/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:07:07 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/12 19:16:07 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	tmp;

	len_dest = ft_strlen((const char *)dest);
	len_src = ft_strlen(src);
	tmp = len_dest;
	if (size < len_dest)
		return (size + len_src);
	while ((len_dest + 1) < size && *src != '\0')
	{
		if (*src != '\0')
		{
			*(dest + len_dest) = *src;
			len_dest += 1;
			src += 1;
		}
	}
	*(dest + len_dest) = '\0';
	return (tmp + len_src);
}
