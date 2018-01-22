/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:04:26 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/15 19:12:41 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_begin(wchar_t wc)
{
	int nb;

	nb = 0;
	if (wc <= 0x7F)
	{
		ft_putchar(wc);
		nb++;
	}
	else if (wc <= 0x7FF)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
		nb += 2;
	}
	return (nb);
}

int		ft_putwchar(wchar_t wc)
{
	int nb;

	nb = 0;
	nb = ft_begin(wc);
	if (wc <= 0xFFFF && nb == 0)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
		nb += 3;
	}
	else if (wc <= 0x10FFFF && nb == 0)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
		nb += 4;
	}
	return (nb);
}
