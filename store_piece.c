/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/09/06 00:23:36 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

void		piece_append(t_piece **head, t_piece *new)
{
	t_piece		*tmp;

	tmp = *head;
	new->head = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_piece		*fillit_lstnew(char **content, size_t i)
{
	t_piece		*new;

	if (!(new = (t_piece*)ft_memalloc(sizeof(t_piece))))
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		while (content[i])
			i++;
		if (!(new->content = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
			return (NULL);
		i = 0;
		while (content[i] != '\0')
		{
			new->content[i] = ft_strdup(content[i]);
			i++;
		}
	}
	new->content_size = i;
	new->next = NULL;
	new->end = 0;
	return (new);
}

char		*fillit_trim(char *dst, char *src, char c, int *i)
{
	while (i[1] < 19)
	{
		if (hash_count(&src[i[1]], 4) != 0)
		{
			while (src[i[1]] != '\n')
			{
				if (src[i[1]] == '#')
					dst[i[2]++] = c;
				if ((i[1] < 15 && (src[i[1]] == '.' && (src[i[1] + 5] == '#')))
			|| (i[1] <= 10 && (src[i[1]] == '.' && (src[i[1] + 10] == '#'))))
					dst[i[2]++] = src[i[1]];
				if ((i[1] > 4 && (src[i[1]] == '.' && (src[i[1] - 5] == '#')))
			|| (i[1] >= 10 && (src[i[1]] == '.' && (src[i[1] - 10] == '#'))))
					dst[i[2]++] = src[i[1]];
				if (src[i[1]] == '\n')
					dst[i[2]++] = '\n';
				i[1]++;
			}
			dst[i[2]++] = '\n';
			i[1]++;
		}
		else
			i[1] = i[1] + 5;
	}
	return (dst);
}

char		**array_piece(char *buf, char c)
{
	char	*trim;
	char	**p_array;
	size_t	d;
	int		i[3];

	d = 0;
	while (d < 3)
		i[d++] = 0;
	if (!(trim = (char*)ft_memalloc(sizeof(trim) * 10)))
		return (NULL);
	ft_bzero(trim, 10);
	trim = fillit_trim(trim, buf, c, i);
	if (!(p_array = ft_strsplit(trim, '\n')))
		return (NULL);
	ft_strdel(&trim);
	return (p_array);
}

t_piece		*get_pieces(char *buf)
{
	unsigned int	loop_count;
	t_piece			*head;
	t_piece			*new;

	loop_count = 0;
	while (loop_count < 26 && *buf != 0)
	{
		if (check_block(buf) == TRUE)
		{
			new = fillit_lstnew((array_piece(buf, (loop_count + 65))), 0);
			new->number = loop_count + 1;
			if (loop_count == 0)
				head = new;
			else
				piece_append(&head, new);
			buf += 21;
			loop_count++;
		}
		else
			return (NULL);
	}
	head->head = head;
	head->end = loop_count - 1;
	piece_append(&head, fillit_lstnew(NULL, 0));
	return (head);
}
