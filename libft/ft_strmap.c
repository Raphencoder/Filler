/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:02:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/13 10:58:07 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		nbltr;
	char	*str;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	nbltr = ft_strlen(s);
	if ((str = (char*)malloc(sizeof(char) * (nbltr + 1))) == 0)
		return (NULL);
	while (nbltr > 0)
	{
		str[i] = f(s[i]);
		i++;
		nbltr--;
	}
	str[i] = '\0';
	return (str);
}
