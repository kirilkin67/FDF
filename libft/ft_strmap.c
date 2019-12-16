/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:05:30 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/19 14:48:32 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;
	size_t	index;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((len + 1) == 0)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = f(s[index]);
		index += 1;
	}
	str[index] = '\0';
	return (str);
}
