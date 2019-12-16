/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:12:58 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/11 11:34:55 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int index;

	index = ft_strlen(dest);
	while (n > 0 && *src != '\0')
	{
		dest[index] = *src;
		index += 1;
		src += 1;
		n -= 1;
	}
	dest[index] = '\0';
	return (dest);
}
