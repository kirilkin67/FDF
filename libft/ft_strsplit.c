/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:45:00 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/21 20:30:12 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	**tab_word(char const *str, char c)
{
	char	**tab;
	size_t	word;

	word = 0;
	while (*str != '\0')
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			word += 1;
		str += 1;
	}
	if ((word + 1) == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	*(tab + word) = NULL;
	return (tab);
}

static void	ft_freestr(char **tab, size_t index)
{
	while (index > 0)
	{
		free(tab[index - 1]);
		index -= 1;
	}
	free(tab);
}

static char	**tab_string(char const *str, char ch)
{
	size_t	len;
	size_t	word;
	char	**tab;

	if (!(tab = tab_word(str, ch)))
		return (NULL);
	word = 0;
	while (*str != '\0')
	{
		len = 0;
		while (*str != ch && *(str++) != '\0')
		{
			len += 1;
			if (*str == ch || *str == '\0')
			{
				if (!(tab[word] = ft_strnew(len)))
					ft_freestr(tab, word);
				if (*str == '\0')
					return (tab);
				word += 1;
			}
		}
		str += 1;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	word;
	size_t	index;
	char	**tab;

	if (!s || !(tab = tab_string(s, c)))
		return (NULL);
	word = 0;
	while (*s != '\0')
	{
		index = 0;
		while (*s != c && *s != '\0')
		{
			tab[word][index] = *s++;
			index += 1;
			if (*s == c || *s == '\0')
				word += 1;
			if (*s == '\0')
				return (tab);
			if (tab == NULL)
				return (NULL);
		}
		s += 1;
	}
	return (tab);
}
