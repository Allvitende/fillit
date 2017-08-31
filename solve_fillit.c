/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 00:16:17 by aquint            #+#    #+#             */
/*   Updated: 2017/08/31 00:06:59 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_lq/libft.h"
#include "fillit.h"
#define TRUE 1
#define FALSE 0



char	**r_fillit_solver(char **board, t_piece *head, int row, int col)
{
	char **piece;
	int	valid;

	piece = head->content;
	if (board[row])
	{
// 	 	ft_putnbr(row);
//		ft_putchar('-');
//		ft_putnbr(col);
	//	ft_putnbr(valid_check(board, piece, row, col));
	//	ft_putchar('\n');
		if ((valid = valid_check(board, piece, row, col)))
		{
			ft_putchar('v');
			ft_putchar('\n');
	//		ft_putarray(board);
			return (place_piece(board, piece, row, col));
		}
		else
		{
			if (board [row][col] != '\0')
				r_fillit_solver(board, head, row, col + 1);
			if (board [row] != '\0') 
				r_fillit_solver(board, head, row + 1, 0);
		}	
	}
	ft_putchar('i');
	return (NULL);
}

void	solve_print(t_piece *head)
{
	unsigned int 	bsize;
	char 			**board;	
	t_piece 		*tmp;
	unsigned int	i;
	unsigned int	c;

	c = 0;
	tmp = head;
	bsize = 2;
	while ((bsize * bsize) < (head->number * 4))
		bsize++;
	if (!(board = fillit_board(bsize)))
		return;
	ft_putnbr(head->number);
	while (head->number >= c)
	{
		if ((r_fillit_solver(board, tmp, 0, 0)))
		{
			ft_putchar('c');
			ft_putarray(board);
			tmp = tmp->next;
			c++;
		}
		else
		{
			ft_putchar('I');
			i = 0;
			while (board[i] != '\0')
			{
				free(board[i]);
				i++;
			}
			free(board);
			if(!(board = fillit_board(++bsize)))
				return;
			tmp = head;
			c = 0;
		}
	}
	ft_putarray(board);
}

int		valid_check(char **board, char **piece,  unsigned int row, unsigned int col)	
{
	unsigned int i;
	unsigned int c;

	i = 0;
	while (piece[i] != '\0')
	{
		c = 0;
		while (piece[i][c] != 0)
		{
			if (piece[i][c] != '.')
			{
				if (((col + c) >= ft_strlen(&board[row][col])) || ((row + i) >= ft_strlen(board[row]))) 
					return (FALSE);
				else
				{
					if (board[row + i][col + c] == '.')
						c++;
					else
						return (FALSE);
				}
			}
			else
				c++;
		}
		i++;

	}
	return (TRUE);
}

char	**place_piece(char **board, char **piece, int row, int col)
{
	int i;
	int c;
	
	i = 0;
	while (piece[i] != '\0')
	{
		c = 0;
		while (piece[i][c] != '\0')
		{
			if (piece[i][c] != '.')
			{
				if (board[row + i][col + c] == '.')
				{
					board[row + i][col + c] = piece[i][c];
				c++;
				}
			}
			else
				c++;
		}
		i++;
	}
	return (board);
}

char	**fillit_board(int size)
{
	char **board;
	int i;
	int col;

	i = 0;
	if (!(board = (char**)ft_memalloc(sizeof(*board) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(board[i] = (char*)ft_memalloc(sizeof(board) * (size + 1))))
			return (NULL);
		col = 0;
		while (col < size)
			board[i][col++] = '.';
		board[i][col] = '\0';
		i++;
	}
	board[i] = NULL;
	return (board);
}
