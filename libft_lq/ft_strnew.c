/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 17:20:45 by aquint            #+#    #+#             */
/*   Updated: 2017/07/21 20:41:30 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * size + 1);
	if (str != NULL)
	{
		while (i <= size + 1)
			str[i++] = '\0';
	}
	return (str);
}
