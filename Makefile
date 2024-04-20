CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = push_swap.c validation.c operations.c operations2.c preparations.c stackfunc.c checker.c
OBJS = $(SRCS:.c=.o)
FTPRINTF_PATH = ./ft_printf
LIBFT_PATH = $(FTPRINTF_PATH)/libft
FTPRINTF = $(FTPRINTF_PATH)/libftprintf.a
LIBFT = $(LIBFT_PATH)/libft.a
NAME = push_swap

all: $(NAME)

test:
	$(CC) validation.c operations.c operations2.c preparations.c stackfunc.c test.c $(FTPRINTF) $(LIBFT) -o test.o

$(NAME): $(FTPRINTF) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(FTPRINTF) $(LIBFT) -o $(NAME)

$(FTPRINTF):
	make -C $(FTPRINTF_PATH) all

clean:
	rm -f $(OBJS)
	make -C $(FTPRINTF_PATH) clean

fclean: clean
	rm -f $(OBJS)
	make -C $(FTPRINTF_PATH) fclean

re:	fclean all

phony: all fclean clean re libft ft_printf push_swap
