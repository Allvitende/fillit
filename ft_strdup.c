/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:05:07 by bschroed          #+#    #+#             */
/*   Updated: 2017/01/16 02:05:08 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;
	char *ret;

	str = ft_strnew(ft_strlen(s1));
	if (!str)
		return (NULL);
	ret = str;
	while (*s1)
		*str++ = *s1++;
	return (ret);
}
