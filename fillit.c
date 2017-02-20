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
#define FALSE 0
//For errors also change file descriptor for errors
// #define GRD(a, b) do{if(a) {b;}}while(0)

// void	check_file(char *buf)
// {
// 	unsigned int	i;
// 	unsigned int	char_count;
// 	unsigned int	valid_block_count;
// 	unsigned int	valid_line_count;
//
// 	i = 0;
// 	char_count = 0;
// 	valid_block_count = 0;
// 	valid_line_count = 0;
// 	while (buf[i] != '\0')
// 	{
// 		if (!valid_character(buf[i], TRUE))
// 		{
// 			ft_puterror("ERROR. Invalid file characters\n");
// 			exit(EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while ((valid_character(buf[i], FALSE)) && buf[i] != '\0')
// 	{
// 		char_count++;
// 		i++;
// 		if (char_count == 4 && buf[i] == '\n' && (valid_character(buf[i + 1], FALSE)) && valid_line_count < 4)
// 		{
// 			valid_line_count++;
// 			char_count = 0;
// 			i++;
// 			continue;
// 		}
// 		if (char_count == 4 && buf[i] == '\n' && buf[i + 1] == '\n' && valid_line_count == 3)
// 		{
// 			if (valid_block(buf[i + 1]) == FALSE)
// 			{
// 				ft_puterror("ERROR. File contains invalid pieces\n");
// 				exit(EXIT_FAILURE);
// 			}
// 			else
// 			{
// 				valid_block_count++;
// 				valid_line_count = 0;
// 				char_count = 0;
// 				i += 2;
// 				continue;
// 			}
// 		}
// 	}
// 	if (char_count != 0 || valid_line_count != 0 || valid_block_count < 1)
// 	{
// 		ft_puterror("ERROR. File contains invalid lines\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (valid_block_count > 26)
// 	{
// 		ft_puterror("ERROR. Too many tetriminos\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		ft_puterror("VALID FILE\n");
// 		exit(EXIT_SUCCESS);
// 	}
// }

int		valid_character(int c, int with_newline)
{
	if (with_newline)
		return (c == '.' || c == '#' || c == '\n');
	else
		return (c == '.' || c == '#' );
}

int		check_block(char *buf)
{
	
}

char	**get_pieces(char *buf)
{
	int		i;
	char	piece_arr[25][20];

	i = 0;
	ft_memset(piece_arr, 0, sizeof(piece_arr));
	while (buf < 546 && check_block(buf) == TRUE)
	{
		piece_arr[i] = extract_piece(buf);
		buf += 21;
		i++;
	}
}

char	*read_file(char *file)
{
	int		fd;
	char	buf[546];

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_puterror("ERROR opening file.\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(buf, 0, sizeof(buf));
	if (read(fd, buf, 546) == -1)
	{
		ft_puterror("ERROR reading file.\n");
		exit(EXIT_FAILURE);
	}
	if (read(fd, buf, 1))
	{
		ft_puterror("ERROR. Exceeds maximum file size.\n");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_puterror("ERROR closing file.\n");
		exit(EXIT_FAILURE);
	}
	return(buf);
}

int	main(int argc, char **argv)
{
	char	*buf;
	char	**pieces;
	if (argc != 2)
	{
		ft_puterror("Usage: ./fillit file\n");
		return (1);
	}
	buf = read_file(argv[1]);
	pieces = get_pieces(buf);
	return (0);
}
