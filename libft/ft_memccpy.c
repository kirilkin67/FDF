/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:22:55 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/13 16:10:14 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *tmp;
	unsigned char *str;
	unsigned char nb;

	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	nb = (unsigned char)c;
	while (n > 0)
	{
		if (*str == nb)
		{
			*tmp = *str;
			return ((void *)(tmp + 1));
		}
		*tmp = *str;
		tmp += 1;
		str += 1;
		n -= 1;
	}
	return (NULL);
}
