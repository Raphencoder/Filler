/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:02:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 18:11:16 by rkrief           ###   ########.fr       */
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
	int			me;
	int			rival;
	int			tabx;
	int			taby;
	int			i;
	int			j;
	int			clonel;
	int			clonem;
	int			touch;
	int			r;
	int			xpiece;
	int			ypiece;
	char		**tab;
	int			**heat;
}				t_size;

typedef struct	s_piece
{
	char		**tab;
	int			score;
	int			bestscore;
	int			piecex;
	int			piecey;
	int			bestx;
	int			besty;
}				t_piece;

int				ft_find_player(char *str, t_size *size);
int				**ft_fill_map(int **heatmap, t_size size, int add, int search);
int				**ft_heat_map(t_size size);
void			ft_take_score(t_piece *piece, t_size size);
char			**ft_copy_all(t_size *size, int fd);
void			ft_freesize(void **str, int i);
void			ft_checkplace(t_piece *piece, t_size size, int m, int l);
int				ft_rival(char c, char r);
int				ft_ally(char c, char a);
int				ft_istab(char c);

#endif
