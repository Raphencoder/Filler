/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:24:10 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/12 13:03:54 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		counter;
	char	*strnew;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	counter = ft_strlen(s1) + ft_strlen(s2);
	if ((strnew = (char*)malloc(sizeof(char) * (counter + 1))) == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		strnew[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strnew[i++] = s2[j];
		j++;
	}
	strnew[i] = '\0';
	return (strnew);
}
