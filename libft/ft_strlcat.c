/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:21:22 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/14 12:14:27 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	n;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	n = size - dst_len;
	dst = ft_strncat(dst, src, n - 1);
	if (size > dst_len + src_len)
		return (ft_strlen(dst));
	return (dst_len + src_len);
}
