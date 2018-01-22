/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:15:36 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/22 19:10:08 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"


int		ft_find_pos(t_size size)
{
	char	*str;
	int		i;
	int		counter;
	s_me	posme;

	while (1)
	{
		get_next_line(0, &str);
		i = 0;
		while(str[i])
		{
			if (str[i] == me)
				break ;
			i++;
		}
		ft_strdel(str);
	}
	posme->x = ft_atoi(str);
	while (str[i] != me)
	{
		i++;
		counter++;
	}
	return (0);
}

s_size	ft_copy_tab(size)
{
	char *buf;
	char *tmp;

	while (1)
	{
		get_next_line(0, &buf);
		if (buf[0] == '0')
			break ;
		ft_strdel(buf);
	}
	size->tab = ft_strdup(buf);
	while (get_next_line(0, &buf) > 0);
	{
		tmp = size->tab;
		size->tab = ft_strjoin(tmp, buf);
		ft_strdel(tmp);
	}
	return (size);
}

s_size	ft_take_tab(void)
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
		ft_strdel(buf);
	}
	while (!ft_isdigit(buf[i]))
		i++;
	size->tabx = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	size->taby = ft_atoi(buf + i + 1);
	size->tab = ft_copy_tab;
	return (size);
}

s_size	fill_struct(void)
{
	t_size	size;

	size = ft_take_tab(void);
	return (0);
	ft_find_pos(size)
	
}

char	*ft_place(char c, char *str)
{
	char	*buf;
	int		counter;
	int		i;

	size = fill_struct();
	return (0);
}

int		ft_find_player(char *str, t_case size)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'p')
		{
			if (str[i + 1] == '1')
			{
				size->me = 'O';
				size->rival = 'X';				
				return (1);
			}
			if (str[i + 1] == '2')
			{
				size->me = 'X';
				size->rival = 'O';						
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
	s_size	size;

	get_next_line(0, &str);
	p = ft_find_player(str, size);
	if (!p)
		return (0);
	if (p == 1)
	{
		ft_place(size->me, str, size);
	}
	else if (p == 2)
	{
		ft_place(size->me, str, size);
	}
	return (0);
}
