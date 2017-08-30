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

#include "./libft_lq/libft.h"
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
	all_pieces = get_pieces(buf);
	//Here is where a 'solve_fillit(all_pieces);' function would go. I've started the file but no code yet. 
/*	ft_putnbr(all_pieces->number); // I stored the total number of pieces in the Head Sruct.
	ft_putchar('\n'); // ^ each lst that is not the head ->number is 0. 
	while (all_pieces->next) //This is a print test to confirm that structs are correctly linked. 
	{
		ft_putarray(all_pieces->content);
		all_pieces = all_pieces->next;
	}
	ft_putarray(all_pieces->content);
	
*/  
	if (solve_print(all_pieces))
		ft_putchar('\n');
	else
		ft_putstr("not solved");
	return (0);
}
