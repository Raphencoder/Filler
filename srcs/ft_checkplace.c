/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/22 20:20:32 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"


int **ft_fill_map(int **heatmap, t_size size, int add, int search)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	j = 0;
	while (i < size.taby)
	{
		while (j < size.tabx)
		{
			if (heatmap[i][j] == search)
			{
				flag++;
				if (add == 1)
				{
					if (j > 0 && i > 0 && heatmap[i - 1][j -1] == 0)
						heatmap[i - 1][j - 1] = add;
					if (j > 0 && i + 1 < size.taby && heatmap[i + 1][j - 1] == 0)
						heatmap[i + 1][j - 1] = add;
					if (j + 1 < size.tabx && i > 0 && heatmap[i - 1][j + 1] == 0)
						heatmap[i - 1][j + 1] = add;
					if (j + 1 < size.tabx && i + 1 < size.taby && heatmap[i + 1][j + 1] == 0)
						heatmap[i + 1][j + 1] = add;
				}
				if (j > 0 && heatmap[i][j - 1] == 0)
					heatmap[i][j - 1] = add;
				if (i + 1 < size.taby && heatmap[i + 1][j] == 0)
					heatmap[i + 1][j] = add;
				if (i > 0 && heatmap[i - 1][j] == 0)
					heatmap[i - 1][j] = add;
				if (j + 1 < size.tabx && heatmap[i][j + 1] == 0)
					heatmap[i][j + 1] = add;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (flag)
		ft_fill_map(heatmap, size, add + 1, add);
	return (heatmap);
}

int **ft_heat_map(t_size size)
{
	int **heatmap;
	int i;
	int j;

	i = 0;
	j = 0;
	heatmap = (int**)ft_memalloc(sizeof(int*) * size.taby);
	while (i < size.taby)
	{
		heatmap[i] = (int*)ft_memalloc(sizeof(int) * size.tabx);
		while(j < size.tabx)
		{
			if (size.tab[i][j] == size.me)
				heatmap[i][j] = -1;
			else if (size.tab[i][j] == size.rival)
				heatmap[i][j] = -5;
			else if (size.tab[i][j] == (size.rival + 32))
				heatmap[i][j] = -6;
			j++;
		}
		j = 0;
		i++;
	}
	heatmap = ft_fill_map(heatmap, size, 1, -5);
	return (heatmap);
}

void ft_take_score(t_piece *piece, t_size size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	size.heat = 0;
//	ft_freesize((void**)size.heat, size.taby);
	size.heat = ft_heat_map(size);
	piece->score = 0;
	while (i < size.ypiece)
	{
		while (j < size.xpiece)
		{
			if (piece->tab[i][j] == '*')
				piece->score = piece->score + size.heat[piece->piecey + i][piece->piecex + j];
			j++;
		}
		j = 0;
		i++;
	}
	if (piece->score < piece->bestscore)
	{
		piece->bestscore = piece->score;
		piece->bestx = piece->piecex;
		piece->besty = piece->piecey;
	}
}

void	ft_checkplace(t_piece *piece, t_size size, int m, int l)
{
	int i;
	int j;
	int touch;
	int	rival;
	int clonel;
	int clonem;

	i = 0;
	rival = 0;
	touch = 0;
	clonel = l;
	clonem = m;
	j = 0;
	while ((size.ypiece - j) > 0 && (clonem + size.ypiece <= size.taby))
	{
		while ((size.xpiece - i) > 0 && (clonel + size.xpiece <= size.tabx))
		{
			if (piece->tab[j][i] == '*' && ft_ally(size.tab[m][l], size.me))
			{
				touch++;
				piece->piecex = clonel;
				piece->piecey = clonem;
			}
			else if (piece->tab[j][i] == '*' && ft_rival(size.tab[m][l], size.rival))
			{
				rival++;
				touch = 0;
				piece->piecex = -1;
				piece->piecey = 0;
				break ;
			}
			l++;
			i++;
		}
		if (rival)
			break ;
		i = 0;
		j++;
		l = clonel;
		if (m < size.taby)
			m++;
		else
			break ;
	}
	if (touch == 1)
	{
		ft_take_score(piece, size);
		j = 50;
		touch = 0;
	}
	if ((size.ypiece - j <= 0 && touch != 1) || rival)
	{
		if (clonel + 1 >= size.tabx)
			ft_checkplace(piece, size, clonem + 1, 0);
		else
			ft_checkplace(piece, size, clonem, clonel + 1);
	}
	if (m >= size.taby && touch != 1)
		return ;
}
