/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/09/05 20:50:29 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"
#define TRUE 1
#define FALSE 0

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
	if ((line_count == 4) && ((*buf == '\n') || (*buf == 0)))
		return (valid_piece(buf_cpy));
	return (FALSE);
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
	if ((bytes_read + 1)  % 21 != 0 || bytes_read == -1 || read(fd, buf, 1)) //find out if /n at very end of file
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
