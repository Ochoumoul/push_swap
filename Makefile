# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 12:23:16 by ochoumou          #+#    #+#              #
#    Updated: 2022/04/05 02:41:01 by ochoumou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

SRC = main.c double_instructions.c instructions.c libft.c longest_list.c sort_helpers.c sort.c stack_helpers.c stack_utils.c stack.c utils.c optimization.c parse.c parse_helper.c ft_split.c custom_sorts.c
BONUS_SRC = checker.c libft.c parse.c ft_split.c utils.c double_instructions.c stack.c get_next_line.c instructions.c stack_utils.c parse_helper.c stack_helpers.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(BONUS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all
