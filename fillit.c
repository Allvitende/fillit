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

int		solve_print(t_piece *head)
{
	int			bsize;
	char		**board;
	t_piece		*tmp;
	int			i;

	i = 0;
	tmp = head;
	bsize = 2;
	while ((bsize * bsize) <= (head->end * 4))
		bsize++;
	if (!(board = fillit_board(bsize)))
		return (0);
	while ((r_fillit_solver(board, head, 0, 0)) == 0)
	{
		ft_arraydel(board);
		if (!(board = fillit_board(++bsize)))
			return (0);
		head = tmp;
	}
	ft_putarray(board);
	ft_arraydel(board);
	return (TRUE);
}

int		main(int argc, char **argv)
{
	char		*buf;
	int			i;
	t_piece		*all_pieces;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit file\n");
		return (1);
	}
	buf = read_file(argv[1]);
	if (!(all_pieces = get_pieces(buf)))
	{
		ft_putstr("error\n");
		exit(EXIT_FAILURE);
	}
	if (!(solve_print(all_pieces)))
		ft_putstr("error\n");
	return (0);
}
