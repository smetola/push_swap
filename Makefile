NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC = main.c \
	push_swap.c \
	economy.c \
	stack_init.c \
	str_utils.c \
	utils.c \
	small_sort.c \
	ft_split.c \
	op_push.c \
	op_swap.c \
	op_rotate.c \
	op_reverse_rot.c \
	free_errors.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
