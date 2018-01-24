/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:54:56 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/23 13:56:35 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "includes/filler.h"

int main()
{
    char *buf;
    int fd;

    fd = open("test6", O_CREAT | O_WRONLY | O_APPEND);

    while (get_next_line(0, &buf) > 0)
    {
        write(fd, buf, ft_strlen(buf));
        write(fd, "\n", 1);
    }

}
