/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:11:51 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/13 19:42:56 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_while(char const *s, char c, char **str)
{
	int			i;
	int			j;
	int			start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
			str[j++] = ft_strsub(s, start, i - start);
	}
	str[j] = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	char		**str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i++])
	{
		if (s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			j++;
	}
	str = (char**)ft_memalloc(sizeof(char*) * (j + 1));
	if (str == NULL)
		return (NULL);
	return (ft_while(s, c, str));
}
