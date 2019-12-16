/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:47:39 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/19 18:59:51 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((len1 + len2 + 1) == 0)
		return (NULL);
	str = ft_strnew(len1 + len2);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (index < (len1 + len2))
	{
		if (index < len1)
			str[index] = s1[index];
		if (index >= len1)
			str[index] = *s2++;
		index += 1;
	}
	return (str);
}
