/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/29 17:45:37 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

t_size	ft_take_tab(int fd, t_piece *piece, t_size size)
{
	int		i;
	char	*buf;

	i = 0;
	get_next_line(fd, &buf);
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	size.taby = ft_atoi(buf + i);
	while (buf[i] && ft_isdigit(buf[i]))
		i++;
	size.tabx = ft_atoi(buf + i + 1);
	ft_strdel(&buf);
	piece->tab = ft_copy_all(&size, fd);
	return (size);
}

void	ft_free_all(t_size *size, t_piece *piece)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size->taby)
	{
		tmp = size->tab[i];
		ft_strdel(&tmp);
		i++;
	}
	ft_memdel((void**)&size->tab);
	i = 0;
	while (piece->tab[i])
		free(piece->tab[i++]);
	free(piece->tab);
}

char	*ft_place(t_size *size, int fd)
{
	char	*buf;
	char	*tmp;
	char	*tmp2;
	t_piece	piece;

	*size = ft_take_tab(fd, &piece, *size);
	piece.bestx = -1;
	piece.bestscore = 10000000;
	ft_checkplace(&piece, *size, 0, 0);
	ft_free_all(size, &piece);
	if (piece.bestx >= 0)
	{
		buf = ft_itoa(piece.besty);
		tmp = buf;
		buf = ft_strjoin(tmp, " ");
		ft_strdel(&tmp);
		tmp = buf;
		tmp2 = ft_itoa(piece.bestx);
		buf = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
		return (buf);
	}
	return ("-1 -1");
}

int		main(void)
{
	int		fd;
	char	*str;
	char	*res;
	t_size	size;

	fd = 0;
	get_next_line(fd, &str);
	ft_find_player(str, &size);
	ft_strdel(&str);
	while (1)
	{
		res = ft_place(&size, fd);
		ft_putendl(res);
		if (ft_strequ("-1 -1", res))
			break ;
		ft_strdel(&res);
	}
	return (0);
}
