/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:38:01 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/13 19:39:14 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if ((newlist = (t_list*)malloc(sizeof(t_list))) == 0)
		return (NULL);
	newlist->next = NULL;
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		return (newlist);
	}
	newlist->content = (void*)malloc(sizeof(void) * content_size);
	newlist->content = ft_memcpy(newlist->content, content, content_size);
	newlist->content_size = content_size;
	return (newlist);
}
