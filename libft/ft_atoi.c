/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:02:12 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/16 13:00:39 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			index;
	int				sign;
	unsigned long	nb;
	unsigned long	max;

	max = 922337203685477580;
	index = 0;
	while (str[index] == ' ' || str[index] == '\n' || str[index] == '\t' ||
		str[index] == '\v' || str[index] == '\r' || str[index] == '\f')
		index += 1;
	sign = (str[index] == '-') ? -1 : 1;
	if (str[index] == '+' || str[index] == '-')
		index += 1;
	nb = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		if ((nb > max || (nb == max && (str[index] - '0') > 7)) && sign == 1)
			return (-1);
		if ((nb > max || (nb == max && (str[index] - '0') > 8)) && sign == -1)
			return (0);
		nb *= 10;
		nb += str[index] - '0';
		index += 1;
	}
	return ((int)(nb * sign));
}
