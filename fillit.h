/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschroed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:03:10 by bschroed          #+#    #+#             */
/*   Updated: 2017/02/17 00:23:37 by bschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>

void				ft_puterror(char const *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);

char *piece_a = {"####"};
char *piece_b = {"#\n#\n#\n#"};
char *piece_c = {"#..\n###"};
char *piece_d = {"##\n#.\n#."};
char *piece_e = {"###\n..#"};
char *piece_f = {".#\n.#\n##"};
char *piece_g = {"..#\n###"};
char *piece_h = {"#.\n#.\n##"};
char *piece_i = {"###\n#.."};
char *piece_j = {"##\n.#\n.#"};
char *piece_k = {"##\n##"};
char *piece_l = {".##\n##."};
char *piece_m = {"#.\n##\n.#"};
char *piece_n = {".#.\n###"};
char *piece_o = {"#.\n##\n#."};
char *piece_p = {"###\n.#."};
char *piece_q = {".#\n##\n.#"};
char *piece_r = {"##.\n.##"};
char *piece_s = {".#\n##\n#."};

#endif
