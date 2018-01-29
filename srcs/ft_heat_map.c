/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:43:03 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		**ft_heat_map(t_size size)
{
	int **heatmap;
	int i;
	int j;

	i = 0;
	j = 0;
	heatmap = (int**)ft_memalloc(sizeof(int*) * (size.taby + 1));
	while (i < size.taby)
	{
		heatmap[i] = (int*)ft_memalloc(sizeof(int) * size.tabx);
		while (j < size.tabx)
		{
			if (size.tab[i][j] == size.me)
				heatmap[i][j] = -1;
			else if (size.tab[i][j] == size.rival ||
size.tab[i][j] == size.rival + 32)
				heatmap[i][j] = -5;
			j++;
		}
		j = 0;
		i++;
	}
	heatmap = ft_fill_map(heatmap, size, 1, -5);
	return (heatmap);
}
