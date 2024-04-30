CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c validation.c operations.c operations2.c preparations.c stackfunc.c doingmath.c solver.c solvercostcal.c solvermove.c
OBJS = $(SRCS:.c=.o)
SRCSB = checker.c validation.c operations.c operations2.c preparations.c stackfunc.c 
FTPRINTF_PATH = ./ft_printf
LIBFT_PATH = $(FTPRINTF_PATH)/libft
FTPRINTF = $(FTPRINTF_PATH)/libftgnlprintf.a
NAME = push_swap
BONUS = checker

all: $(NAME)

bonus: $(BONUS)

$(BONUS): 
	echo "bonus"

$(NAME): $(FTPRINTF) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(FTPRINTF) -o $(NAME)

$(FTPRINTF):
	make -C $(FTPRINTF_PATH) all

clean:
	rm -f $(OBJS)
	make -C $(FTPRINTF_PATH) clean

fclean: clean
	rm -f $(OBJS) $(NAME)
	make -C $(FTPRINTF_PATH) fclean

re:	fclean all

phony: all fclean clean re libft ft_printf push_swap
