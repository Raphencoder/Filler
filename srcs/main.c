/* ************************************************************************** */
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



int		ft_findmove(t_size size)
{
	int i;
	int counter;

	i = 0;
	counter++;
	while (size.tab[i] != (size.rival + 32) && size.tab[i])
		i++;
	if (!size.tab[i])
		return (0);
	while(!ft_isdigit(size.tab[i]))
		i--;
	while(ft_isdigit(size.tab[i]))
		i--;
	size.yme = ft_atoi(size.tab + i + 1);
	while (size.tab[i] != me)
	{
		i++;
		counter++;
	}
	size.xme = counter - 5;
	return (1);
}

void	ft_findrival(t_size rival)
{
	int		i;
	int		counter;

	i = 0;
	counter++;
	if (ft_findmove(size));
		return ;
	while (size.tab[i] != size.rival)
		i++;
	while(!ft_isdigit(size.tab[i]))
		i--;
	while(ft_isdigit(size.tab[i]))
		i--;
	size.yrival = ft_atoi(size.tab + i + 1);
	while (size.tab[i] != rival)
	{
		i++;
		counter++;
	}
	size.xrival = counter - 5;
}

void	ft_find_posme(t_size size)
{
	int		i;
	int		counter;

	i = 0;
	counter++;
	while (size.tab[i] != size.me)
		i++;
	while(!ft_isdigit(size.tab[i]))
		i--;
	while(ft_isdigit(size.tab[i]))
		i--;
	size.yme = ft_atoi(size.tab + i + 1);
	while (size.tab[i] != me)
	{
		i++;
		counter++;
	}
	size.xme = counter - 5;
	ft_findrival(size);
}



char	*ft_copy_tab(t_size size)
{
	char *buf;
	char *str;
	char *tmp;

	while (1)
	{
		get_next_line(0, &buf);
		if (buf[0] == '0')
			break ;
		ft_strdel(&buf);
	}
	str = ft_strdup(buf);
	ft_strdel(&buf);
	while (get_next_line(0, &buf) > 0)
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp);
	}
	return (str);
}

t_size	ft_take_tab(void)
{
	char	*buf;
	int		i;
	t_size	size;

	i = 0;
	while (1)
	{
		get_next_line(0, &buf);
		if (buf[0] == 'P')
			break ;
		ft_strdel(&buf);
	}
	while (!ft_isdigit(buf[i]))
		i++;
	size.tabx = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	size.taby = ft_atoi(buf + i + 1);
	size.tab = (char*)ft_copy_tab;
	return (size);
}

t_size	fill_struct(void)
{
	t_size	size;

	size = ft_take_tab();
	ft_find_posme(size);
	ft_find_posrival(size);

}

char	*ft_place(char c, char *str, t_size size)
{
	char	*buf;
	int		counter;
	int		i;

	size = fill_struct();
	return (0);
}

int		ft_find_player(char *str, t_size size)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p')
		{
			if (str[i + 1] == '1')
			{
				size.me = 'O';
				size.rival = 'X';				
				return (1);
			}
			if (str[i + 1] == '2')
			{
				size.me = 'X';
				size.rival = 'O';						
				return (2);
			}
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	char	*str;
	int		p;
	t_size	size;

	get_next_line(0, &str);
	p = ft_find_player(str, size);
	if (!p)
		return (0);
	if (p == 1)
	{
		ft_place(size.me, str, size);
	}
	else if (p == 2)
	{
		ft_place(size.me, str, size);
	}
	return (0);
}
