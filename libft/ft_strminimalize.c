/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strminimalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:11:29 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/20 00:11:17 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strminimalize(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') && str[i] != 'X')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
