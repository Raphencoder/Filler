/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:54:31 by Raphael           #+#    #+#             */
/*   Updated: 2017/11/12 15:08:21 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (needle[len] != '\0')
		len++;
	if (len == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (((char*)haystack) + i - len);
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
