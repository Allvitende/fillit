/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/08/17 22:46:16 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define	TRUE  1
#define	FALSE 0

/*char	**remove_cols(char **piece, unsigned int arr_height)
{

}

char	**remove_row(char **piece, unsigned int delete_row)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	row_count;
	char			**new_piece;

	i = 0;
	j = 0;
	row_count = sizeof(piece) / sizeof(piece[0]);
	new_piece = malloc(sizeof(*new_piece) * (row_count - 1));
	if (new_piece)
	{
		while (i < (row_count - 1))
		{
			new_piece[i] = malloc(sizeof(*new_piece[i]) * 5);
			i++;
		}
	}
	i = 0;
	while (i < row_count)
	{
		if (i == delete_row)
		{
			i++;
			continue;
		}
		else
		{
			piece[i] = new_piece[j];
			i++;
			j++;
		}
	}
	return (new_piece);
}
*
char	**trim_piece(char **piece)
{
	unsigned int	i;
	unsigned int	rows_removed;
	unsigned int	arr_height;
	char			**new_piece;

	i = 0;
	rows_removed = 0;
	while (i < 4)
	{
		if (hash_count(piece[i], 4) == 0)
		{
			new_piece = remove_row(piece, i);
			rows_removed++;
		}
		i++;
	}
	i = 0;
	arr_height = 4 - rows_removed;
	new_piece = remove_cols(new_piece, arr_height);
	return (new_piece);
}
*
char	**copy_piece(char *buf)
{
	unsigned int i;
	unsigned int j;
	char	piece[4][5];

	i = 0;
	j = 0;
	k = 0;
	while (k < 21)
	{
		if (*buf != '\n')
		{
			piece[i][j] = *buf;
			j++;
		}
		if (*buf == '\n')
		{
			piece[i][j] = '\0';
			i++;
			j = 0;
		}
		buf++;
		k++;
	}
	return (piece);
}
*/
int		hash_count(char *buf, unsigned int index)
{
	unsigned int	i;
	unsigned int	hash_count;

	i = 0;
	hash_count = 0;
	while (i < index && buf[i] != 0)
	{
		if (buf[i] == '#')
			hash_count++;
		i++;
	}
	return (hash_count);
}

int		valid_piece(char *buf)
{
	unsigned int	i;
	unsigned int	connections;

	i = 0;
	connections = 0;
	if (hash_count(buf, 19) != 4)
		return (FALSE);
	while (i < 19 && buf[i] != 0)
	{
		if (buf[i] == '#' && buf[i + 1] == '#')
			connections++;
		if (i > 0 && (buf[i] == '#' && buf[i - 1] == '#'))
			connections++;
		if (i < 15 && (buf[i] == '#' && buf[i + 5] == '#'))
			connections++;
		if (i > 4 && (buf[i] == '#' && buf[i - 5] == '#'))
			connections++;
		i++;
	}
	return (connections == 6 || connections == 8);
}

int		check_line(char *buf)
{
	unsigned int	i;

	i = 0;
	while ((buf[i] == '.' || buf[i] == '#') && i < 4)
		i++;
	if (i == 4 && buf[i] == '\n')
		return (TRUE);
	else
		return (FALSE);
}

int		check_block(char *buf)
{
	unsigned int	i;
	unsigned int	line_count;
	char			*buf_cpy;

	i = 0;
	line_count = 0;
	buf_cpy = buf;
	while (line_count < 4 && check_line(buf) == TRUE)
	{
		line_count++;
		buf += 5;
	}
	if (line_count == 4 && *buf == '\n')
		return (valid_piece(buf_cpy));
	return (FALSE);
}

void	get_pieces(char *buf)
{
	unsigned int	loop_count;

	loop_count = 0;
	while (loop_count < 26 && *buf != 0)
	{
		if (check_block(buf) == TRUE)
		{
			ft_putnbr(loop_count);
			ft_putstr("Valid\n");
			ft_putstr(buf);
			//t_list *ft_shapetolist(char *str);
		//	ft_strsplit(buf, '\n'); //Ideas for this -> Use strncpy or memncpy to cpy 21 bits to a new str and then strsplit to create a 2d	array. Alternative, trim rows and columns from the string instead of from the  and then strsplit. 
			buf += 21;
			loop_count++;
		}
		else
		{
			ft_puterror("error: invalid block\n");
			exit(EXIT_FAILURE);
		}
	}
}

char	*read_file(char *file)
{
	int		fd;
	int		bytes_read;
	char	buf[546];
	char	*buf_cpy;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_puterror("error: opening file.\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(buf, 0, sizeof(buf));
	bytes_read = read(fd, buf, 546);
	if (bytes_read % 21 != 0 || bytes_read == -1 || read(fd, buf, 1)) //find out if /n at very end of file
	{
		ft_puterror("error: invalid file.\n");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_puterror("error: closing file.\n");
		exit(EXIT_FAILURE);
	}
	buf_cpy = ft_strdup(buf);
	return(buf_cpy);
}

int		main(int argc, char **argv)
{
	char	*buf;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_puterror("Usage: ./fillit file\n");
		return (1);
	}
	buf = read_file(argv[1]);
	get_pieces(buf);
	return (0);
}
