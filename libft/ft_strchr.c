/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:19:28 by Raphael           #+#    #+#             */
/*   Updated: 2017/11/12 13:05:03 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	clone;
	int		i;

	i = 0;
	clone = (char)c;
	while (*s != '\0' && *s != clone)
		s++;
	if (*s == '\0' && c != '\0')
		return (NULL);
	return ((char*)s);
}
