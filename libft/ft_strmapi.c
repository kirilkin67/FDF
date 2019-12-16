/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:32:12 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/19 15:00:08 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
		index += 1;
	if ((index + 1) == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = f(index, s[index]);
		index += 1;
	}
	str[index] = '\0';
	return (str);
}
