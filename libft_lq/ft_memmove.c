/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 19:23:00 by aquint            #+#    #+#             */
/*   Updated: 2017/08/07 19:01:29 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmpd;
	char *tmps;

	tmpd = dst;
	tmps = (char*)src;
	if ((dst - src) < 0)
	{
		ft_memcpy(dst, src, len);
	}
	if ((dst - src) > 0)
	{
		while (len > 0)
		{
			tmpd[len - 1] = tmps[len - 1];
			len--;
		}
	}
	return (dst);
}
