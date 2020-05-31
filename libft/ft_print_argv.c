/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:31:00 by wrhett            #+#    #+#             */
/*   Updated: 2020/05/31 18:31:50 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_print_argv(char **argv)
{
	int n;
	int index;

	n = 1;
	while (argv[n] != NULL)
	{
		index = 0;
		while (argv[n][index] != '\0')
		{
			ft_putchar(argv[n][index]);
			index += 1;
		}
		ft_putchar('\n');
		n += 1;
	}
}
