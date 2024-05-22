/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:56 by hulim             #+#    #+#             */
/*   Updated: 2024/05/22 16:17:06 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				top;
	int				*arr;
}	t_stack;

// pushswap.c
int		getstrstrsize(char **str);
void	freenumstr(char **numstr);
char	**copyfromargv(char **argv, int argc);
void	solve(t_stack *stacka, t_stack *stackb, int size);

// validation.c
int		isargsintandnodup(int size, char **args);
int		isstrnum(char *numstr);
int		isintwithinlimt(char *numstr);
int		istherenodup(int size, char **args);
int		checkifsorted(t_stack *stacka, int size);

// solver.c
void	solve2(t_stack *stack1, char *aorb);
void	solve3(t_stack *stack1, char *aorb);
void	solvesmall(t_stack *stacka, t_stack *stackb);
void	solveusingcost(t_stack *stacka, t_stack *stackb);

// solvercostcal.c
int		checkrotneeded(t_stack *from, t_stack *to, int findex);
int		*findminrotindex(int *rotlist, int sizefrom, int sizeto);
void	updateminmoves(int currfrom, int currto, int *minmoves, int *output);
void	findlowestcostmove(t_stack *from, t_stack *to);

// solvermove.c
void	moveupdown(t_stack *stacka, t_stack *stackb, int *bestchoice);
void	noncommonsteps(t_stack *stacka, t_stack *stackb, int *bestchoice);

// doingmath.c 
int		positiveit(int i);
int		findmax2(int a, int b);
int		findmin2(int a, int b);
void	getcloserto0(int *a);

// operations.c
void	sab(t_stack *stack1, char *aorb);
void	ss(t_stack *stacka, t_stack *stackb);
void	pab(t_stack *stacka, t_stack *stackb, char *aorb);

// operations2.c
void	rab(t_stack *stack1, char *aorb);
void	rr(t_stack *stacka, t_stack *stackb);
void	rrab(t_stack *stack1, char *aorb);
void	rrr(t_stack *stacka, t_stack *stackb);
void	repeatops(char *op, int times, t_stack *stacka, t_stack *stackb);

// preparations.c
int		setupstacks(t_stack *stacka, t_stack *stackb, int size);
void	populatestacka(t_stack *stacka, char **numbersstr, int size);
void	freestack(t_stack *stacka, t_stack *stackb);

// stackfunc.c
void	pushnum(t_stack *stack1, int num);
int		popnum(t_stack *stack1);
int		findmaxreturnindex(t_stack *stack1);
int		findminreturnindex(t_stack *stack1);
int		findminreturnindexrange(t_stack *stack1, int range);

#endif