/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:27:10 by wrhett            #+#    #+#             */
/*   Updated: 2019/10/04 18:27:49 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *str, size_t size)
{
	t_list *newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (newlist == NULL)
		return (NULL);
	newlist->content = (void *)malloc(size);
	if (newlist->content == NULL)
	{
		free(newlist);
		return (NULL);
	}
	if (str == NULL || size == 0)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		ft_memcpy(newlist->content, str, size);
		newlist->content_size = size;
	}
	newlist->next = NULL;
	return (newlist);
}
