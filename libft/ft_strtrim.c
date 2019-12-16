/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:56:52 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/15 16:54:20 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	in;
	size_t	new;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	in = 0;
	while ((s[in] == ' ' || s[in] == '\n' || s[in] == '\t') && s[in] != '\0')
		in += 1;
	if (len == in || *s == '\0')
		return (str = ft_strnew(1));
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len -= 1;
	if (!(str = ft_strnew(len - in)))
		return (NULL);
	new = 0;
	while (in < len)
	{
		str[new] = s[in];
		new += 1;
		in += 1;
	}
	return (str);
}
