/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:21:13 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/21 20:23:44 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *fnd, size_t len)
{
	const char	*src;
	const char	*tmp;
	int			n;

	if (*fnd == 0)
		return ((char *)str);
	while (len > 0 && *str)
	{
		tmp = str;
		src = fnd;
		n = len;
		while (*src == *tmp && n > 0)
		{
			if (*(src + 1) == '\0')
				return ((char *)str);
			src += 1;
			tmp += 1;
			n -= 1;
		}
		src = fnd;
		str += 1;
		len -= 1;
	}
	return (NULL);
}
