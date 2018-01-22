/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:35:13 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/12 01:59:53 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
