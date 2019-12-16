/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:47:56 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/18 13:58:29 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	if (s != NULL && f != NULL)
	{
		index = 0;
		while (s[index] != '\0')
		{
			f(index, &s[index]);
			index += 1;
		}
	}
}
