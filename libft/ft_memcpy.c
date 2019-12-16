/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:42:24 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/13 19:39:42 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*str;

	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*tmp = *str;
		tmp += 1;
		str += 1;
		n -= 1;
	}
	return ((void *)dst);
}
