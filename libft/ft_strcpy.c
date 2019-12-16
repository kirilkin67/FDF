/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:16:55 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/11 11:30:03 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char *tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*tmp = *src;
		tmp += 1;
		src += 1;
	}
	*tmp = '\0';
	return (dest);
}
