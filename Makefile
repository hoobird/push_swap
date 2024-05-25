CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c validation.c operations.c operations2.c preparations.c stackfunc.c doingmath.c solver.c solvercostcal.c solvermove.c arghandling.c
OBJS = $(SRCS:.c=.o)
SRCSB = checker.c validation.c operations.c operations2.c preparations.c stackfunc.c doingmath.c solver.c solvercostcal.c solvermove.c arghandling.c
OBJSB = $(SRCSB:.c=.o)
FTPRINTF_PATH = ./ft_printf
LIBFT_PATH = $(FTPRINTF_PATH)/libft
FTPRINTF = $(FTPRINTF_PATH)/libftgnlprintf.a
NAME = push_swap
BONUS = checker

all: $(NAME)

bonus: $(BONUS) all

$(BONUS): $(FTPRINTF) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(FTPRINTF) -o $(BONUS)

$(NAME): $(FTPRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FTPRINTF):
	make -C $(FTPRINTF_PATH) all

clean:
	rm -f $(OBJS)
	make -C $(FTPRINTF_PATH) clean

fclean: clean
	rm -f $(OBJS) $(NAME) $(BONUS)
	make -C $(FTPRINTF_PATH) fclean

re:	fclean all

phony: all fclean clean re libft ft_printf push_swap
