NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

SRC = main.c double_instructions.c instructions.c libft.c longest_list.c sort_helpers.c sort.c stack_helpers.c stack_utils.c stack.c utils.c optimization.c
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