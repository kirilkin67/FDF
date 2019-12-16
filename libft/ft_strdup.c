/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:35:14 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/20 17:44:11 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *src)
{
	size_t		index;
	char		*str;

	index = 0;
	while (src[index] != '\0')
		index += 1;
	if ((index + 1) == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		str[index] = src[index];
		index += 1;
	}
	str[index] = '\0';
	return (str);
}
