/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:22:45 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/14 12:01:45 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = i;
	while (s[j] != '\0')
		j++;
	j--;
	while (j > 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	len = j - i + 1;
	str = ft_strsub(s, i, len);
	return (str);
}
