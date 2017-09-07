/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/08/29 19:56:37 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*buf;
	int			i;
	t_piece		*all_pieces;	

	i = 0;
	if (argc != 2)
	{
		ft_puterror("Usage: ./fillit file\n");
		return (1);
	}
	buf = read_file(argv[1]);
	if (!(all_pieces = get_pieces(buf)))
	{
		ft_puterror("error:invalid blaock\n");
		exit(EXIT_FAILURE);
	}

	if (solve_print(all_pieces))
		return (0);
	else
	{
		ft_puterror("error:doesnt solve\n");
	}
	return (0);
}
