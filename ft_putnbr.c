/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <bschroed@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:44:27 by bschroed          #+#    #+#             */
/*   Updated: 2017/01/06 13:44:28 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long n_copy;

	n_copy = n;
	if (n_copy < 0)
	{
		ft_putchar('-');
		n_copy = -n_copy;
	}
	if (n_copy > 9)
	{
		ft_putnbr(n_copy / 10);
		ft_putnbr(n_copy % 10);
	}
	else
		ft_putchar(n_copy + '0');
}
