/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:10:00 by wrhett            #+#    #+#             */
/*   Updated: 2019/12/18 18:00:01 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		lower_in_upper(int c)
{
	if (c >= 'a' && c <= 'f')
		c -= 32;
	return (c);
}

static int		value_digit(char c)
{
	int	digit;

	digit = 0;
	if (c >= '0' && c <= '9')
		digit = c - '0';
	if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		digit = lower_in_upper(c) - 'A' + 10;
	return (digit);
}

static t_bool	ft_has_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (false);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (true);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (true);
		if (base == 8)
			return (true);
	}
	return (false);
}

t_bool			ft_isnumber(char *str, int base)
{
	const char	*value = "0123456789ABCDEF";
	int			i;
	size_t		digits;

	i = 0;
	digits = 0;
	while ((str[i] >= 9 && str[i] <= 13) && str[i] == 32)
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (false);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] >= value[0] && lower_in_upper(str[i]) <= (value[base - 1]))
	{
		i++;
		digits++;
	}
	return ((!str[i] && digits) ? true : false);
}

int				ft_atoi_base(const char *str, int base)
{
	const char		*value = "0123456789ABCDEF";
	unsigned long	result;
	int				i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) && str[i] == 32)
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (false);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= value[0] && lower_in_upper(str[i]) <= (value[base - 1]))
		result = result * base + value_digit(str[i++]);
	return ((int)(result * sign));
}
