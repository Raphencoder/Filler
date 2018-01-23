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

#include "../includes/filler.h"


void	ft_checkplace(t_piece *piece, t_size size, int m, int l)
{
	int i;
	int j;
	int touch;
	int clonel;
	int clonem;

	i = 0;
	touch = 0;
	clonel = l;
	clonem = m;
	j = 0;
	while ((size.ypiece - j) > 0)
	{
		while ((size.xpiece - i) > 0)
		{
			if (piece->tab[j][i] == '*' && size.tab[m][l] == size.me)
			{
					touch++;
					piece->piecex = clonel;
					piece->piecey = clonem;
			}
			i++;
			l++;
		}
		i = 0;
		j++;
		l = clonel;
		if (m < size.taby)
			m++;
		else
			break ;
	}
	if (size.ypiece - j <= 0 && touch != 1)
	{
		if (clonel + 1 >= size.tabx)
			ft_checkplace(piece, size, clonem + 1, 0);
		else
			ft_checkplace(piece, size, clonem, clonel + 1);
	}
	if (m >= size.taby && touch != 1)
		return ;
	if (touch == 1)
		return ;
}

char	**ft_copy_tab(int i, int fd, char **buf, int y)
{
	char	**str;
	int		j;

	j = 0;
	str = (char**)ft_memalloc(sizeof(char*) * y + 1);
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

char	**ft_copy_all(t_size *size, int fd)
{
	char *buf;
	t_piece	piece;
	int	i;

	i = 0;
	while (1)
	{
		get_next_line(fd, &buf);
		if (buf[0] == '0')
			break ;
		else
			ft_strdel(&buf);
	}
	while (!ft_istab(buf[i]))
		i++;
	size->tab = ft_copy_tab(i, 0, &buf, size->taby);
	size->xpiece = ft_take_x(buf);
	size->ypiece = ft_take_y(buf);
	piece.tab = (char**)ft_memalloc(sizeof(char*) * (size->ypiece + 1));
	i = 0;
	while (get_next_line(0, &buf) > 0)
		piece.tab[i++] = buf;
	return (piece.tab);
}

t_size	ft_take_tab(int fd, t_piece *piece, char *buf)
{
	int		i;
	t_size	size;

	i = 0;
	ft_find_player(buf, &size);
	ft_strdel(&buf);
	while (1)
	{
		get_next_line(fd, &buf);
		if (buf[0] == 'P')
			break ;
		ft_strdel(&buf);
	}
	while (!ft_isdigit(buf[i]))
		i++;
	size.taby = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	size.tabx = ft_atoi(buf + i + 1);
	piece->tab = ft_copy_all(&size, 0);
	return (size);
}

char	*ft_place(char *str, t_size *size, int fd)
{
	char	*buf;
	t_piece	piece;
	int		counter;
	int		i;

	*size = ft_take_tab(fd, &piece, str);
	ft_checkplace(&piece, *size, 0, 0);
	if (piece.piecex)
	{
		buf = ft_itoa(piece.piecex);
		buf = ft_strjoin(buf, " ");
		buf = ft_strjoin(buf, ft_itoa(piece.piecey));
		return (buf);
	}
	return (0);
}

int		main(void)
{
	int		fd;
	char	*str;
	char 	*res;
	t_size	size;
	t_piece	piece;

	fd = open("test5", O_RDONLY);
	get_next_line(fd, &str);
	res = ft_place(str, &size, fd);
	ft_putstr(res);
//	close(0);
	return (0);
}
