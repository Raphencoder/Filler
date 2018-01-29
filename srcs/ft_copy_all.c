/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:46:00 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

char	**ft_copy_tab(int fd, char **buf, int y)
{
	char	**str;
	int		j;

	j = 0;
	str = (char**)ft_memalloc(sizeof(char*) * (y + 1));
	while (*buf[0] != 'P')
	{
		str[j] = ft_strdup(*buf + 4);
		ft_strdel(buf);
		get_next_line(fd, buf);
		j++;
	}
	str[j] = NULL;
	return (str);
}

int		ft_take_x(char *str)
{
	int	i;
	int nb;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	nb = ft_atoi(str + i);
	return (nb);
}

int		ft_take_y(char *str)
{
	int i;
	int nb;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	nb = ft_atoi(str + i);
	return (nb);
}

void	ft_take_piece(t_piece *piece, t_size size, int fd)
{
	int		i;
	char	*buf;

	i = 0;
	while (i < size.ypiece)
	{
		get_next_line(fd, &buf);
		piece->tab[i++] = ft_strdup(buf);
		ft_strdel(&buf);
	}
}

char	**ft_copy_all(t_size *size, int fd)
{
	char	*buf;
	t_piece	piece;
	int		i;

	i = 0;
	while (i < 2)
	{
		if (i)
			ft_strdel(&buf);
		get_next_line(fd, &buf);
		i++;
	}
	while (buf[i] && !ft_istab(buf[i]))
		i++;
	size->tab = ft_copy_tab(fd, &buf, size->taby);
	size->xpiece = ft_take_x(buf);
	size->ypiece = ft_take_y(buf);
	ft_strdel(&buf);
	piece.tab = (char**)ft_memalloc(sizeof(char*) * (size->ypiece + 1));
	ft_take_piece(&piece, *size, fd);
	return (piece.tab);
}
