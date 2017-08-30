/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 23:12:53 by aquint            #+#    #+#             */
/*   Updated: 2017/08/07 19:00:58 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *tmpd;
	char *tmps;

	tmpd = dst;
	tmps = (char*)src;
	while (n > 0)
	{
		*tmpd = *tmps;
		tmpd++;
		tmps++;
		n--;
	}
	return (dst);
}
