/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <raphaelkriefbm@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:44:56 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/14 10:07:12 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		var;
	int		counter;

	counter = 0;
	i = 0;
	nb = 0;
	var = 1;
	while (str[i] == 32 || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			var = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i++] - '0');
		counter++;
	}
	if (counter > 18 && var == -1)
		return (0);
	else if (counter > 18 && var == 1)
		return (-1);
	return (nb * var);
}
