/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:59:57 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/13 19:01:09 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;
	char	clonec;

	s1 = (char*)dst;
	s2 = (char*)src;
	clonec = c;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == clonec)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
