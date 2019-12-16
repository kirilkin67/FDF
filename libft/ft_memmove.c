/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:17:14 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/14 12:38:50 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp;
	unsigned char *str;

	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (tmp < str)
	{
		while (len--)
			*tmp++ = *str++;
	}
	if (tmp > str)
	{
		tmp += len;
		str += len;
		while (len--)
		{
			tmp -= 1;
			str -= 1;
			*tmp = *str;
		}
	}
	return ((void *)dst);
}
