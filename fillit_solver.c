/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 00:16:17 by aquint            #+#    #+#             */
/*   Updated: 2017/08/24 00:16:41 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_lq/libft.h"
#include "fillit.h"
#define TRUE 1
#define FALSE 0

void	fillit_solve(char **board, t_piece *head, int row, int col)
{
	char	**new_board;
	int		new_bsize;
	int		i;

	i = 0;
    while (!(valid_check(board, head, (unsigned int)row, (unsigned int)col)))
	{
		while (board[i] != '\0')
		{
			free(board[i]);
			i++;
		}
		free(board);
		new_bsize = row + 1;
		if (!(new_board = fillit_board(new_bsize)))
			ft_putstr("Bad allocation");
		row = new_bsize;
		col = new_bsize;
	}
}

int	valid_check(char **board, t_piece *head,  unsigned int row, unsigned int col)
{
	unsigned int i;
	unsigned int j;


	i = 0;
	if (head == NULL)
		return (TRUE);
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (board[i][j] == '.' && place_piece(board, head, i, j, row))
				valid_check(board, head->next, row, col);
			j++;
		}
		i++;

	}
	return (FALSE);
}

int place_piece(char **board, t_piece *head, int row, int col, int size)
{
	int i;
	int c;
	int width;
	int height;

	i = 0;
	width = ft_strlen(head->content[0]);
	height = head->content_size;
	ft_putarray(board);
	while (i < width)
	{
		c = 0;
		while (c < height)
		{
			if (row + i < size && col + c < size && board[row + i][col + c] != '.' && head->content[i][c] != '.')
				return (FALSE);
			c++;
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		c = 0;
		while (c < width)
		{
			if (row + i < size && col + c < size && head->content[i][c] != '.')
				board[row + i][col + c] = head->content[i][c];
			c++;
		}
		i++;
	}
	return(TRUE);
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

int		solve_setup(t_piece *head)
{
	unsigned int	bsize;
	char			**board;

	bsize = 2;
	while ((bsize * bsize) < (head->number * 4))
		bsize++;
	if (!(board = fillit_board(bsize)))
		return (FALSE);
	fillit_solve(board, head, bsize, bsize);
	return (TRUE);
}
