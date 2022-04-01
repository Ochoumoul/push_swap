# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 12:23:16 by ochoumou          #+#    #+#              #
#    Updated: 2022/04/01 12:58:53 by ochoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

SRC = main.c double_instructions.c instructions.c libft.c longest_list.c sort_helpers.c sort.c stack_helpers.c stack_utils.c stack.c utils.c optimization.c validation.c ft_split.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# The source files for the checker:
# checker.c libft.c validation.c ft_split.c utils.c double_instructions.c stack.c get_next_line.c instructions.c stack_utils.c