/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:18:21 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/18 13:56:46 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *tmp;
	unsigned char nb;

	tmp = (unsigned char *)src;
	nb = (unsigned char)c;
	while (n > 0)
	{
		if (*tmp == nb)
			return (tmp);
		tmp += 1;
		n -= 1;
	}
	return (NULL);
}
