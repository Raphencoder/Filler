/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:02:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/22 19:52:23 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "unistd.h"
# include "stdlib.h"

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
	char	*tab;
}				t_size;

#endif
