/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:44:19 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/12 13:05:36 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		nbltr;
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	nbltr = ft_strlen(s);
	if ((str = (char*)malloc(sizeof(char) * (nbltr + 1))) == 0)
		return (NULL);
	while (nbltr > 0)
	{
		str[i] = f(i, s[i]);
		i++;
		nbltr--;
	}
	str[i] = '\0';
	return (str);
}
