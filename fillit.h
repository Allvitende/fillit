/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:03:10 by bschroed          #+#    #+#             */
/*   Updated: 2017/09/06 00:41:19 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# define TRUE 1
# define FALSE 0

typedef struct	s_piece
{

	char			**content;
	size_t			content_size;
	unsigned int	number;
	int				end;
	struct s_piece	*head;
	struct s_piece	*next;
}				t_piece;

/* fillit.c  */

int				solve_print(t_piece *head);

/* piece_validation.c */

int				hash_count(char *buf, unsigned int index);
int				valid_piece(char *buf);
int				check_line(char *buf);
int				check_block(char *buf);
char			*read_file(char *file);

/* store_piece.c */

void			piece_append(t_piece **head, t_piece *new);
t_piece			*fillit_lstnew(char **content, size_t i);
char			*fillit_trim(char *dst, char *src, char c, int *i);
char			**array_piece(char *buf, char c);
t_piece			*get_pieces(char *buf);

/* solve_fillit.c */

int				r_fillit_solver(char **board, t_piece *head, int row, int col);
int				valid_check(char **board, char **piece, size_t row, size_t col);
char			**place_piece(char **board, char **piece, int row, int col);
char			**delete_piece(char **board, t_piece *head, int row, int col);
char			**fillit_board(int size);
int				solve_print(t_piece *head);

#endif
