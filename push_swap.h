/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:56 by hulim             #+#    #+#             */
/*   Updated: 2024/04/18 19:26:12 by hulim            ###   ########.fr       */
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

void 	populatestacka(t_stack *stacka, char** numbersstr, int size);
void	solve(t_stack *stacka, t_stack *stackb, int size);
int		checkifsorted(t_stack *stacka, int size);
int		isargsintandnodup(int size, char **args);
int		isstrnum(char *numstr);
int		isintwithinlimt(char *numstr);
int		istherenodup(int size, char **args);
int		setupstacks(t_stack *stacka, t_stack *stackb, int size);
void	freestack(t_stack *stacka, t_stack *stackb);
void	pushnum(t_stack *stack1, int num);
int		popnum(t_stack *stack1);
int		findminreturnindex(t_stack *stack1);
int		findmaxreturnindex(t_stack *stack1);
void	sab(t_stack *stack1, char *aorb);
void	ss(t_stack *stacka, t_stack *stackb);
void	pab(t_stack *stacka, t_stack *stackb, char *aorb);
void	rab(t_stack *stack1, char *aorb);
void	rr(t_stack *stacka, t_stack *stackb);
void	rrab(t_stack *stack1, char *aorb);
void	rrr(t_stack *stacka, t_stack *stackb);

#endif