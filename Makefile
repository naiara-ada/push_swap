NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MY_SOURCES = push_swap.c \
				error.c \
				ft_split.c \
				push_swap_utils.c \
				push_swap_utils2.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				sort_big.c \
				sort_big_moves.c \
				sort.c \
				swap.c \
				validation.c 

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