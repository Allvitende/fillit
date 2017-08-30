/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 13:50:38 by aquint            #+#    #+#             */
/*   Updated: 2017/07/21 02:40:04 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (void*)malloc(size);
	if (str != NULL)
	{
		while (i <= size)
			str[i++] = 0;
	}
	return (str);
}
