/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:12:46 by aquint            #+#    #+#             */
/*   Updated: 2017/08/09 14:30:48 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(char const *s, char d)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != d)
	{
		i++;
	}
	return (i);
}
