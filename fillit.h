/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:03:10 by bschroed          #+#    #+#             */
/*   Updated: 2017/08/29 20:47:54 by aquint           ###   ########.fr       */
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
	struct s_piece	*next;
}				t_piece;

/*
 * fillit.c
 * currently has main
 * might be where print of final comes in
 */

/*
 *piece_validation.c
 */
int					hash_count(char *buf, unsigned int index); //tests num of #
int					valid_piece(char *buf); //tests valid piece config
int					check_line(char *buf); //checks chars and num of chars in line
int					check_block(char *buf); //checks lines in block
char				*read_file(char *file); //checks num of bytes, valid file

/*
 * store_piece.c
 */

void				piece_append(t_piece **head, t_piece *new); // appends new piece to end of linked list
t_piece				*fillit_lstnew(char **content, size_t content_size); //mallocs new t_piece
char				*fillit_trim(char *dst, char *src, char c); //trims and alphabetisizes piece
char				**array_piece(char *buf, char c); //creates piece array
t_piece				*get_pieces(char *buf); //sends file to be validated, saves piece as linked list

/*
 *  solve_fillit.c
 */
int				r_fillit_solver(char **board, t_piece *head, int row, int col);
int				valid_check(char **board, char **piece, unsigned  int row, unsigned int col);
char 			**place_piece(char **board, char **piece, int row, int col);
char 			**fillit_board(int size);
int				solve_print(t_piece *head);

/* quick reaction of functions we likely need. 
 *  * Set 2day array square based on minimum possibility
 *  * recursive function to test each block against top left empty corner
 *  * test if 2day array can be placed 
 */

/*
 * Other things to be consider
 *  * Free used data 
 *  * checking for memory leaks 
 *  * Norminette 
*/ 
#endif
