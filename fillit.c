/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/02/16 05:14:48 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define  BUF_SIZE 546
//For errors also change file descriptor for errors
// #define GRD(a, b) do{if(a) {b;}}while(0) 
void	filechecker(char **buf)
{
	while (**buf != \0)

	while (buf[0][i] == '.' || buf[0][i] == '#' || buf[0][i] == '\n')
	{
		if ((buf[0][i] == '\n') && (i % 16 != 0))
		{
			ft_putstr("Error. Invalid file input");
			exit(EXIT_FAILURE);
		}
	}
}

void	filereader(char *file)		
{
	int		fd;
	char	*buf[BUF_SIZE];

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
		ft_putstr("Error. Incorrect file length.\n");
		exit(EXIT_FAILURE);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Error closing file.\n");
		exit(EXIT_FAILURE);
	}
	filechecker(&buf);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit file\n");
		return (1);
	}
	filereader(argv[1]);
	return (0);
}
