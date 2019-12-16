/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:44:58 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/12 21:17:24 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	tmp;

	str = (unsigned char *)b;
	tmp = (unsigned char)c;
	while (len > 0)
	{
		*str = tmp;
		str += 1;
		len -= 1;
	}
	return (b);
}
