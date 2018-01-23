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

void	ft_copy_all(t_size *size, int fd)
{
	char *buf;
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
	size->tab = ft_copy_tab(i, fd, &buf, size->taby);
	size->xpiece = ft_take_x(buf);
	size->ypiece = ft_take_y(buf);
	size->piece = (char**)ft_memalloc(sizeof(char*) * (size->ypiece + 1));
	i = 0;
	while (get_next_line(fd, &buf) > 0)
		size->piece[i++] = buf;
}

t_size	ft_take_tab(int fd)
{
	char	*buf;
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
	ft_copy_all(&size, fd);
	return (size);
}

char	*ft_place(char *str, t_size *size, int fd)
{
	char	*buf;
	int		counter;
	int		i;

	*size = ft_take_tab(fd);
	printf("me = %c\n", size->me);
	printf("rival = %c\n", size->rival);
	printf("tabx = %d\n", size->tabx);
	printf("taby = %d\n", size->taby);
	printf("xpiece = %d\n", size->xpiece);
	printf("ypiece = %d\n\n", size->ypiece);
	i = 0;
	printf("piece =\n");
	while (size->piece[i])
	{
		printf("%s\n", size->piece[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("tab =\n");
	while (size->tab[i])
	{
		printf("%s\n", size->tab[i]);
		i++;
	}
	return (0);
}

int		main(void)
{
	int		fd;
	char	*str;
	t_size	size;

	fd = open("test5", O_RDONLY);
	get_next_line(fd, &str);
	ft_place(str, &size, fd);
	close(fd);
	return (0);
}
