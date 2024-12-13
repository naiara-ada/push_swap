NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MY_SOURCES = ./src/push_swap.c \
				./error/error.c \
				./utils/ft_split.c \
				./utils/push_swap_utils.c \
				./utils/push_swap_utils2.c \
				./commands/push.c \
				./commands/reverse_rotate.c \
				./commands/rotate.c \
				./src/sort_big.c \
				./src/sort_big_moves.c \
				./src/sort.c \
				./commands/swap.c \
				./utils/validation.c 

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
