/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 00:16:17 by aquint            #+#    #+#             */
/*   Updated: 2017/09/06 00:41:15 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#define TRUE 1
#define FALSE 0

int		r_fillit_solver(char **board, t_piece *head, int row, int col)
{
	if (head->content == NULL)
	{
		head->head->end = 1;
		return (TRUE);
	}
	if (board[row] == '\0')
		head->head->end = 0;
	else if ((valid_check(board, head->content, row, col)) == FALSE)
	{
		if (board[row][col] == '\0')
			r_fillit_solver(board, head, row + 1, 0);
		else
			r_fillit_solver(board, head, row, col + 1);
	}
	else
	{
		place_piece(board, head->content, row, col);
		r_fillit_solver(board, head->next, 0, 0);
		if (head->head->end != 1)
			delete_piece(board, head, row, col);
		if (head->head->end == 1)
			return (TRUE);
	}
	return (FALSE);
}

int		valid_check(char **board, char **piece, size_t row, size_t col)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	while (piece[i] != '\0')
	{
		c = 0;
		while (piece[i][c] != '\0')
		{
			if (piece[i][c] != '.')
			{
				if (((col + c) >= (ft_strlen(board[row]))) ||
				((row + i) >= (ft_strlen(board[row]))))
					return (FALSE);
				if (!(board[row + i][col + c] == '.'))
					return (FALSE);
			}
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
	while (piece[i])
	{
		c = 0;
		while (piece[i][c])
		{
			if (piece[i][c] != '.')
			{
				if (board[row + i][col + c] == '.')
				{
					board[row + i][col + c] = piece[i][c];
				}
			}
			c++;
		}
		i++;
	}
	return (board);
}

char	**delete_piece(char **board, t_piece *head, int row, int col)
{
	int		i;
	int		c;
	char	ch;

	i = 0;
	ch = (head->number) + 64;
	while (board[i] != '\0')
	{
		c = 0;
		while (board[i][c] != '\0')
		{
			if (board[i][c] == ch)
				board[i][c] = '.';
			c++;
		}
		i++;
	}
	r_fillit_solver(board, head, row, col + 1);
	return (board);
}

char	**fillit_board(int size)
{
	char	**board;
	int		i;
	int		col;

	i = 0;
	if (!(board = (char**)ft_memalloc(sizeof(*board) * (size + 1))))
		return (NULL);
	bzero(board, size + 1);
	while (i < size)
	{
		if (!(board[i] = (char*)ft_memalloc(sizeof(board) * (size + 1))))
			return (NULL);
		bzero(board[i], size + 1);
		col = 0;
		while (col < size)
			board[i][col++] = '.';
		board[i][col] = '\0';
		i++;
	}
	board[i] = NULL;
	return (board);
}
