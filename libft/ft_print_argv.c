/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:31:00 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/18 17:37:52 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_print_argv(char **argv)
{
	int n;
	int index;

	n = 1;
	while (argv[n] != '\0')
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
