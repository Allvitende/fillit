/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:57:52 by aquint            #+#    #+#             */
/*   Updated: 2017/08/03 19:58:48 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	int tmpc;

	tmpc = c;
	if ((tmpc > 64 && tmpc < 91) || (tmpc > 96 && tmpc < 123))
		return (1);
	else
		return (0);
}