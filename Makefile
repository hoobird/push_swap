CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c validation.c
OBJS = $(SRCS:.c=.o)
FTPRINTF_PATH = ./ft_printf
LIBFT_PATH = $(FTPRINTF_PATH)/libft
FTPRINTF = $(FTPRINTF_PATH)/libftprintf.a
LIBFT = $(LIBFT_PATH)/libft.a
NAME = push_swap

all: $(NAME)

$(NAME): $(FTPRINTF)
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
