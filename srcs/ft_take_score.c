/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:43:58 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_free_heatmap(t_size *size)
{
	int i;

	i = 0;
	while (size->heat[i])
		free(size->heat[i++]);
	free(size->heat);
}

void	ft_take_score(t_piece *piece, t_size size)
{
	size.i = 0;
	size.j = 0;
	size.heat = ft_heat_map(size);
	piece->score = 0;
	while (size.i < size.ypiece)
	{
		while (size.j < size.xpiece)
		{
			if (piece->tab[size.i][size.j] == '*')
				piece->score = piece->score +
size.heat[piece->piecey + size.i][piece->piecex + size.j];
			size.j++;
		}
		size.j = 0;
		size.i++;
	}
	if (piece->score < piece->bestscore)
	{
		piece->bestscore = piece->score;
		piece->bestx = piece->piecex;
		piece->besty = piece->piecey;
	}
	ft_free_heatmap(&size);
}
