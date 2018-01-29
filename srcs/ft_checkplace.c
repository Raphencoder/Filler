/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:39:35 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_touch(t_piece *piece, int *touch, int clonel, int clonem)
{
	*touch = *touch + 1;
	piece->piecex = clonel;
	piece->piecey = clonem;
}

int		ft_outofwhile(t_size *size, int *l, int *clonel, int *m)
{
	size->i = 0;
	size->j++;
	*l = *clonel;
	if (*m < size->taby)
	{
		*m = *m + 1;
		return (1);
	}
	return (0);
}

void	ft_check(t_size *size, int *m, int *l, t_piece *piece)
{
	while ((size->ypiece - size->j) > 0 &&
(size->clonem + size->ypiece <= size->taby))
	{
		while ((size->xpiece - size->i) > 0 &&
(size->clonel + size->xpiece <= size->tabx))
		{
			if (piece->tab[size->j][size->i] == '*' &&
ft_ally(size->tab[*m][*l], size->me))
				ft_touch(piece, &size->touch, size->clonel, size->clonem);
			else if (piece->tab[size->j][size->i] == '*' &&
ft_rival(size->tab[*m][*l], size->rival))
			{
				size->r++;
				size->touch = 0;
				break ;
			}
			*l = *l + 1;
			size->i++;
		}
		if (size->r)
			break ;
		if (!ft_outofwhile(size, l, &size->clonel, m))
			break ;
	}
}

void	ft_checkplace(t_piece *piece, t_size size, int m, int l)
{
	size.r = 0;
	size.touch = 0;
	size.i = 0;
	size.clonel = l;
	size.j = 0;
	size.clonem = m;
	ft_check(&size, &m, &l, piece);
	if (size.touch == 1)
	{
		ft_take_score(piece, size);
		size.j = 50;
		size.touch = 0;
	}
	if ((size.ypiece - size.j <= 0 && size.touch != 1) || size.r)
	{
		if (size.clonel + 1 >= size.tabx)
			ft_checkplace(piece, size, size.clonem + 1, 0);
		else
			ft_checkplace(piece, size, size.clonem, size.clonel + 1);
	}
	if (m >= size.taby && size.touch != 1)
		return ;
}
