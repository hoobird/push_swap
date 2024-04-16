/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:12:49 by hulim             #+#    #+#             */
/*   Updated: 2024/04/16 21:19:53 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sab(t_stack *stack1, char aorb);
void    ss(t_stack *stacka, t_stack *stackb);
void    pab(t_stack *stack1, char aorb);
void    ra(t_stack *stacka, t_stack *stackb);
void    rb(t_stack *stacka, t_stack *stackb);
void    rr(t_stack *stacka, t_stack *stackb);
void    rra(t_stack *stacka, t_stack *stackb);
void    rrb(t_stack *stacka, t_stack *stackb);
void    rrr(t_stack *stacka, t_stack *stackb);

void    sab(t_stack *stack1, char aorb)
{
	int	temp;
	int	topindex;

	if (stack1->top < 1)
		return ;
	topindex = stack1->top;
	temp = stack1->arr[topindex];
	stack1->arr[topindex] = stack1->arr[topindex-1];
	stack1->arr[topindex-1] = temp;
	ft_putstr_fd(ft_strjoin(ft_strjoin("s", &aorb), "\n"), 1);
}

void    ss(t_stack *stacka, t_stack *stackb)
{
	sab(stacka, 'a');
	sab(stackb, 'b');
	ft_putstr_fd("ss", 1);
}

void    pab(t_stack *stack1, char aorb)
{
	int	popped;

	
	ft_putstr_fd(ft_strjoin(ft_strjoin("p", &aorb), "\n"), 1);
}
