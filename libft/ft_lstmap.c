/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:43:48 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/13 20:43:50 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;

	if (lst == NULL)
		return (NULL);
	newlist = (t_list*)malloc(sizeof(t_list));
	newlist = f(lst);
	if (lst->next != NULL)
		newlist->next = ft_lstmap(lst->next, f);
	return (newlist);
}
