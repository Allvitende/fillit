# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschroed <bschroed@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 14:04:01 by bschroed          #+#    #+#              #
#    Updated: 2017/08/17 22:09:35 by aquint           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROGRAM = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =
GREEN = \x1b[32;01m
YELLOW = \x1b[33;01m
RED = \x1b[31;01m
NO_COLOR = \x1b[0m

SRCDIR = ./libft/*.c

SRC += libft/ft_putstr.c
SRC += libft/ft_memset.c
SRC += libft/ft_putnbr.c
SRC += libft/ft_putchar.c
SRC += libft/ft_puterror.c
SRC += libft/ft_strdup.c
SRC += libft/ft_strnew.c
SRC += libft/ft_strlen.c

MAIN = fillit.c

OBJ = $(SRC:.c=.o)

MAX			:= $(words $(OBJ))
increment	= $1 x
n			:= x
COUNTER		= $(words $n)$(eval n := $(call increment, $n))

all: $(NAME)

$(OBJ): %.o: %.c
	@printf "$(YELLOW)\r>>COMPILING: [$(GREEN)%d$(YELLOW)/$(GREEN)%d$(YELLOW)]" $(COUNTER) $(MAX)
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@printf "\n"
	@echo "$(YELLOW)>>CREATING LIBRARY...$(NO_COLOR)"
	@ar rcs $@ $+
	@echo "$(GREEN)>>DONE!"

$(PROGRAM): $(NAME) $(MAIN)
	$(CC) $(MAIN) -L. -lft $(CFLAGS) -o $(PROGRAM)


clean:
	@echo "$(RED)>>DELETING OBJECT FILES..."
	@rm -f $(OBJ)
	@echo "$(GREEN)>>DONE!"
fclean: clean
	@echo "$(RED)>>DELETING $(NAME)"
	@rm -f $(NAME)
	@echo "$(GREEN)>>DONE!"
re: fclean all

.PHONY: all clean fclean re
