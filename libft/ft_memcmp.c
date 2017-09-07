/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:22:41 by aquint            #+#    #+#             */
/*   Updated: 2017/08/03 22:36:26 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *tmp_1;
	const unsigned char *tmp_2;

	tmp_1 = s1;
	tmp_2 = s2;
	if (n == 0)
		return (0);
	while (*tmp_1 == *tmp_2 && n > 1)
	{
		tmp_1++;
		tmp_2++;
		n--;
	}
	return (*tmp_1 - *tmp_2);
}
