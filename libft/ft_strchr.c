/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:26:35 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/18 18:47:00 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t len;

	len = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)str + len);
	while (len > 0)
	{
		if ((char)c == *str)
			return ((char *)str);
		str += 1;
		len -= 1;
	}
	return (NULL);
}
