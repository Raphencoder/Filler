/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:41:06 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_ifaddone(int **heatmap, t_size size, int i, int j)
{
	if (j > 0 && i > 0 && heatmap[i - 1][j - 1] == 0)
		heatmap[i - 1][j - 1] = 1;
	if (j > 0 && i + 1 < size.taby && heatmap[i + 1][j - 1] == 0)
		heatmap[i + 1][j - 1] = 1;
	if (j + 1 < size.tabx && i > 0 && heatmap[i - 1][j + 1] == 0)
		heatmap[i - 1][j + 1] = 1;
	if (j + 1 < size.tabx && i + 1 < size.taby && heatmap[i + 1][j + 1] == 0)
		heatmap[i + 1][j + 1] = 1;
}

void	ft_fill_it(int **heatmap, t_size size, int add)
{
	if (size.j > 0 && heatmap[size.i][size.j - 1] == 0)
		heatmap[size.i][size.j - 1] = add;
	if (size.i + 1 < size.taby && heatmap[size.i + 1][size.j] == 0)
		heatmap[size.i + 1][size.j] = add;
	if (size.i > 0 && heatmap[size.i - 1][size.j] == 0)
		heatmap[size.i - 1][size.j] = add;
	if (size.j + 1 < size.tabx && heatmap[size.i][size.j + 1] == 0)
		heatmap[size.i][size.j + 1] = add;
}

int		**ft_fill_map(int **heatmap, t_size size, int add, int search)
{
	int flag;

	size.i = 0;
	flag = 0;
	size.j = 0;
	while (size.i < size.taby)
	{
		while (size.j < size.tabx)
		{
			if (heatmap[size.i][size.j] == search)
			{
				flag++;
				if (add == 1)
					ft_ifaddone(heatmap, size, size.i, size.j);
				ft_fill_it(heatmap, size, add);
			}
			size.j++;
		}
		size.j = 0;
		size.i++;
	}
	if (flag)
		ft_fill_map(heatmap, size, add + 1, add);
	return (heatmap);
}
