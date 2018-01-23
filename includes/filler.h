/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:02:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/23 16:35:54 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
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
	char	**piece;
	char	**tab;
}				t_size;

int		ft_find_player(char *str, t_size *size);
int		ft_istab(char c);

#endif
