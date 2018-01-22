/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/22 13:10:35 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_movefwrd(char **str, int fd, int i)
{
	char	*strnew;
	int		k;
	int		j;

	j = 0;
	k = i;
	while (str[fd][k])
	{
		k++;
		j++;
	}
	strnew = ft_strnew(j);
	ft_strncpy(strnew, str[fd] + i, j);
	ft_strclr(str[fd]);
	free(str[fd]);
	return (strnew);
}

void		ft_fillstr(char **str, char *buf, int fd)
{
	char	*tmp;
	int		j;

	if (str[fd] == NULL)
		str[fd] = ft_strdup(buf);
	else
	{
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		j = ft_strlen(str[fd]);
		str[fd][j + 1] = '\0';
		if (tmp)
			ft_strdel(&tmp);
	}
}

int			ft_error(int i, char **str, int fd, char **line)
{
	if (i == -1)
		return (-1);
	if (str[fd] == NULL)
	{
		*line = ft_strnew(10000);
		return (0);
	}
	if (str[fd][0] == '\0')
	{
		ft_strclr(str[fd]);
		*line = ft_strnew(100000);
		return (0);
	}
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	*line = ft_strnew(i);
	ft_strncpy(*line, str[fd], i);
	str[fd] = ft_movefwrd(str, fd, i + 1);
	return (1);
}

int			find_endl(char *buf, char **str, int fd)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			ft_fillstr(str, buf, fd);
			return (1);
		}
		i++;
	}
	if (i == ft_strlen(buf))
		return (0);
	if (i == 0)
		return (-1);
	ft_fillstr(str, buf, fd);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			j;
	static char **str;
	char		buf[BUFF_SIZE + 1];
	int			i;

	if (str == NULL)
		str = ft_memalloc(sizeof(char *) * 4865);
	if (fd < 0)
		return (-1);
	while ((j = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[j] = '\0';
		if (find_endl(buf, str, fd) == 1)
			break ;
		ft_fillstr(str, buf, fd);
	}
	i = ft_error(j, str, fd, line);
	if (i == 0)
		return (0);
	if (i == -1)
		return (-1);
	return (1);
}
