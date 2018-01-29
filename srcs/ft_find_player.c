/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:41:27 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:41:29 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		ft_find_player(char *str, t_size *size)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p')
		{
			if (str[i + 1] == '1')
			{
				size->me = 'O';
				size->rival = 'X';
				return (1);
			}
			if (str[i + 1] == '2')
			{
				size->me = 'X';
				size->rival = 'O';
				return (2);
			}
		}
		i++;
	}
	return (0);
}
