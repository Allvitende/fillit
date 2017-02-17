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
#define  BUF_SIZE 546
//For errors also change file descriptor for errors
// #define GRD(a, b) do{if(a) {b;}}while(0)
int		ValidCharacter(int c)
{
	return (c == '.' || c == '#' || c == '\n');
}

void	FileChecker(char *buf)
{
	unsigned int	i;
	unsigned int	char_count;
	unsigned int	valid_block_count;
	unsigned int	valid_line_count;

	i = 0;
	char_count = 0;
	valid_block_count = 0;
	valid_line_count = 0;
	while (buf[i] != '\0')
	{
		if (!ValidCharacter(buf[i]))
		{
			ft_putstr("ERROR. Invalid file characters\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while ((buf[i] == '.' || buf[i] == '#') && buf[i] != '\0')
	{
		char_count++;
		i++;
		if (char_count == 4 && buf[i] == '\n' && (buf[i + 1] == '.' || buf[i + 1] == '#') && valid_line_count < 4)
		{
			valid_line_count++;
			char_count = 0;
			i++;
			continue;
		}
		if (char_count == 4 && buf[i] == '\n' && buf[i + 1] == '\n' && valid_line_count == 3)
		{
			valid_block_count++;
			valid_line_count = 0;
			char_count = 0;
			i += 2;
			continue;
		}
	}
	if (char_count != 0 || valid_line_count != 0 || valid_block_count < 1)
	{
		ft_putstr("ERROR. Invalid lines in file\n");
		exit(EXIT_FAILURE);
	}
	else if (valid_block_count > 26)
	{
		ft_putstr("ERROR. Too many tetriminos\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr("Valid file\n");
		exit(EXIT_SUCCESS);
	}
}

void	FileReader(char *file)
{
	int		fd;
	char	buf[BUF_SIZE];

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(buf, '\0', sizeof(buf));
	if (read(fd, buf, BUF_SIZE) == -1)
	{
		ft_putstr("Error reading file.\n");
		exit(EXIT_FAILURE);
	}
	if (read(fd, buf, 1))
	{
		ft_putstr("Error. Exeeds maximum file size.\n");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Error closing file.\n");
		exit(EXIT_FAILURE);
	}
	FileChecker(buf);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit file\n");
		return (1);
	}
	FileReader(argv[1]);
	return (0);
}
