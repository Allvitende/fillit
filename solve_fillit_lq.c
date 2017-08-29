/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit_lq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 00:16:17 by aquint            #+#    #+#             */
/*   Updated: 2017/08/24 00:16:41 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#define TRUE 1
#define FALSE 0

int		r_fillit_solver(char **board, t_piece *head, int row, int col)
{
	char **piece = piece->content;
	int valid;

	valid = valid_check(board, piece, row, col);
	
	if (valid == false)
	{
		if (board [row][col] != '\0')
			r_fillit_solver(board, head, row, col + 1);
		if (board [row] != '\0')
			r_fillit_solver(board, head, row + 1, col = 0);
		return (FALSE)			
	}
	if (valid = TRUE)
	{
		place_piece(board, piece, row, col);
		if (head->next != NULL)
		{
			head = head->next; 
			r_fillit_solver(board, head, row, col);
		}
		return (TRUE);
	}
}

int		valid_check(char **board, char **piece,  int row, int col)	
{
	int i;
	int c;

	int i = 0;
	while (piece[i] != 0)
	{
		c = 0;
		while (piece[i][c] != 0)
		{
			if (piece[i][c] != '.')
			{
				if (board[row + i][col + c] == '.')
					c++;
				else
					return (FALSE)
			}
			else
				c++;
		}
		i++;
	}
}

char	**place_piece(char **board, char **piece, int row, int col)
{
	int i = 0;
	while (piece[i] != 0)
	{
		c = 0;
		while (piece[i][c] != 0)
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
	if (!(board = (char**)ft_memalloc(sizeof(**board) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(board[i] = (char*)ft_memalloc(sizeof(*board) * (size + 1))))
			return (NULL);
		col = 0;
		while (col < size)
			board[i][col++] = '.';
		board[i][r] = '\0';
		i++;
	}
	board[i] = '\0';
	return (board);
}

int	solve_print(t_piece *head)
{
	int 	bsize;
	char 	**board;	
	
	bsize = 2;
	while ((bsize * bsize) < (head->number * 4))
		bsize++;
	if (!(board = fillit_board(bsize)))
		return (NULL);
	while ((r_fillit_solver(board, piece, 0, 0) == FALSE))
	{
		free(board);
		if (!(board = fillit_board(++bsize)))
			return (NULL);
	}
	ft_putarray(board);
	return (TRUE);
}
