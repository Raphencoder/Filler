/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:02:32 by Raphael           #+#    #+#             */
/*   Updated: 2017/11/12 15:53:57 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*clone;
	int		j;

	i = 0;
	if (s1 == NULL || !s1)
		return (NULL);
	if (((clone = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)) == 0))
		return (NULL);
	while (s1[i])
		i++;
	j = 0;
	while (s1[j])
	{
		clone[j] = s1[j];
		j++;
	}
	clone[j] = '\0';
	return (clone);
}
