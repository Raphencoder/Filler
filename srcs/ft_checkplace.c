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

int	ft_checkplace(t_piece *piece, t_size size, int m, int l)
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
	if ((size.ypiece - j <= 0 && touch != 1) || rival)
	{
		if (clonel + 1 >= size.tabx)
			ft_checkplace(piece, size, clonem + 1, 0);
		else
			ft_checkplace(piece, size, clonem, clonel + 1);
	}
	if (m >= size.taby && touch != 1)
		return (1);
	if (touch == 1)
		return (0);
	return (1);
}
