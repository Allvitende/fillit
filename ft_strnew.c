/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 01:26:57 by bschroed          #+#    #+#             */
/*   Updated: 2017/01/16 01:26:59 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	end;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	end = size + 1;
	if (!ret)
		return (NULL);
	while (end--)
		*ret++ = '\0';
	return (ret - (size + 1));
}
