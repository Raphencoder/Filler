/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:02:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/23 19:52:29 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./includes/libft.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

typedef struct	s_size
{
	int		me;
	int		rival;
	int		tabx;
	int		taby;
	int 	xme;
	int		yme;
	int		xrival;
	int		yrival;
	int		newx;
	int		newy;
	int		xpiece;
	int		ypiece;
	char	**tab;
}				t_size;

typedef struct	s_piece
{
	char **tab;
	int	touch;
	int	piecex;
	int	piecey;
}				t_piece;

int		ft_find_player(char *str, t_size *size);
int		ft_checkplace(t_piece *piece, t_size size, int m, int l);
int     ft_rival(char c, char r);
int     ft_ally(char c, char a);
int		ft_istab(char c);

#endif
