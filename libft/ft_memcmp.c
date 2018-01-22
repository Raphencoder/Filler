/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:25:27 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/12 12:47:32 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*clones1;
	char	*clones2;
	size_t	i;

	clones1 = (char*)s1;
	clones2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		if (clones1[i] != clones2[i])
			return ((unsigned char)clones1[i] - (unsigned char)clones2[i]);
		i++;
	}
	return (0);
}
