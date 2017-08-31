/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:00:14 by bschroed          #+#    #+#             */
/*   Updated: 2017/08/30 19:12:58 by aquint           ###   ########.fr       */
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

	if (!(new = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	if (content == NULL)
	{
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		if (!(new->content = (char**)malloc(sizeof(char**) * content_size)))
			return (NULL);
		ft_memcpy(new->content, content, (content_size * sizeof(char*)));
		new->content_size = content_size;
	}
	new->next = NULL;
	new->number = 0;
	new->alpha = 'A';
	new->head = new;
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

	if (!(trim = (char*)ft_memalloc(10)))
		return (NULL);
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
				head = fillit_lstnew((array_piece(buf, (loop_count + 65))), 11);
			else
			{
				new = fillit_lstnew((array_piece(buf, (loop_count + 65))), 11);
				new->alpha = (loop_count + 65);
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
	return (head);
}
