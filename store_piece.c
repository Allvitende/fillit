/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/08/29 19:35:53 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_lq/libft.h"
#include "fillit.h"

void	piece_append(t_piece **head, t_piece *new)
{
	t_piece	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_piece	*fillit_lstnew(char **content, size_t content_size)
{
	t_piece	*new;
	size_t	i;

	i = 0;
	if (!(new = (t_piece*)ft_memalloc(sizeof(t_piece))))
		return (NULL);
	if (content_size == 0)
	{
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		while (content[i])
			i++;
		if (!(new->content = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
			return (NULL);
		i = 0;
		while (content[i])
		{
			new->content[i] = ft_strdup(content[i]);
			i++;
		}
		new->content_size = content_size;
	}
	new->next = NULL;
	new->end = 0;
	new->number = 0;
	return (new);
}

char	*fillit_trim(char *dst, char *src, char c)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (i < 19)
	{
		if (hash_count(&src[i], 4) != 0)
		{
			while (src[i] != '\n')
			{
				if (src[i] == '#')
					dst[i2++] = c;
				if (i < 15 && (src[i] == '.' && (src[i + 5] == '#')))
					dst[i2++] = src[i];
				else if (i < 10 && (src[i] == '.' && (src[i + 10] == '#')))
					dst[i2++] = src[i];
				if (i > 4 && (src[i] == '.' && (src[i - 5] == '#')))
					dst[i2++] = src[i];
				else if (i > 10 && (src[i] == '.' && (src[i - 10] == '#')))
					dst[i2++] = src[i];
				if (src[i] == '\n')
					dst[i2++] = '\n';
				i++;
			}
			dst[i2++] = '\n';
			i++;
		}
		else
			i = i + 5;
	}
	dst[i2] = '\0';
	return(dst);
}

char	**array_piece(char *buf, char c)
{
	char *trim;
	char **p_array;

	if (!(trim = (char*)ft_memalloc(sizeof(trim) * 10)))
		return (NULL);
	ft_bzero(trim, 10);
	trim = fillit_trim(trim, buf, c);
	if (!(p_array = ft_strsplit(trim, '\n')))
		return (NULL);
	free (trim);
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
			if (loop_count == 0)
				head = fillit_lstnew((array_piece(buf, (loop_count + 65))), 1);
			else
			{
				new = fillit_lstnew((array_piece(buf, (loop_count + 65))), 1);
				new->number = loop_count + 1;
				new->head = head;
				piece_append(&head, new);
			}
			buf += 21;
			loop_count++;
		}
		else
		{
			ft_puterror("error: invalid block\n");
			exit(EXIT_FAILURE);
		}
	}
	head->number = loop_count;
	new = fillit_lstnew(NULL, 0);
	new->head = head;
	piece_append(&head,new);
	return (head);
}
