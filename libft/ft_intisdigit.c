/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:56:11 by rkrief            #+#    #+#             */
/*   Updated: 2017/12/13 17:17:10 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_intisdigit(int c)
{
	if (c > 9)
		return (0);
	else if (c <= 9 && c >= 0)
		return (1);
	return (0);
}
