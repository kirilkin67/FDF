/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:32:31 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/11 12:49:37 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcat(char *dest, const char *src)
{
	int index;

	index = ft_strlen(dest);
	while (*src != '\0')
	{
		dest[index] = *src;
		src += 1;
		index += 1;
	}
	dest[index] = '\0';
	return (dest);
}
