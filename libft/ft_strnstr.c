/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:58:32 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/12 15:22:54 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	scan;

	i = 0;
	j = 0;
	scan = 0;
	while (needle[scan])
		scan++;
	if (scan == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i] && i < (int)len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (((char*)haystack) + i - scan);
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
