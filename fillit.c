/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/02/17 00:23:35 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#define	TRUE  1
#define	FALSE 0

//trim rows then columns!
char	**trim_piece(char **piece)
{
	unsigned int i;

	i = 0;
	while (i < 4)
	{
		if (hash_count(piece[i], 4) == 0)
			//copy into new array without this row;
		i++;
	}
	while ()

}

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

int		hash_count(char *buf, int index)
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
			ft_putstr("Valid\n");
			trim_piece(copy_piece(buf));
			buf += 21;
			loop_count++;
		}
		else
			exit(EXIT_FAILURE);
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
		ft_puterror("ERROR opening file.\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(buf, 0, sizeof(buf));
	bytes_read = read(fd, buf, 546);
	if (bytes_read % 21 != 0 || bytes_read == -1 || read(fd, buf, 1))
	{
		ft_puterror("ERROR. Invalid file.\n");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_puterror("ERROR closing file.\n");
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
