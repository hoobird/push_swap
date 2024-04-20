/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:12:49 by hulim             #+#    #+#             */
/*   Updated: 2024/04/21 05:13:00 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rab(t_stack *stack1, char *aorb)
{
	int newlast;
	int count;

	count = stack1->top;
	if (count <= 0)
		return ;
	newlast = stack1->arr[count];
	while (count > 0)
	{
		stack1->arr[count] = stack1->arr[count - 1];
		count--;
	}
	stack1->arr[0] = newlast;
	if (aorb != 0)
		ft_putstr_fd(ft_strjoin(ft_strjoin("r", aorb), "\n"), 1);
}

void    rr(t_stack *stacka, t_stack *stackb)
{
	rab(stacka, 0);
	rab(stackb, 0);
	ft_putstr_fd("rr\n", 1);
}

void    rrab(t_stack *stack1, char *aorb)
{
	int newfirst;
	int count;

	count = 0;
	if (stack1->top <= 0)
		return ;
	newfirst = stack1->arr[0];
	while (count < stack1->top)
	{
		stack1->arr[count] = stack1->arr[count+1];
		count++;
	}
	stack1->arr[stack1->top] = newfirst;
	if (aorb != 0)
		ft_putstr_fd(ft_strjoin(ft_strjoin("rr", aorb), "\n"), 1);
}

void    rrr(t_stack *stacka, t_stack *stackb)
{
	rrab(stacka, 0);
	rrab(stackb, 0);
	ft_putstr_fd("rrr\n", 1);
}

void	repeatops(char *op, int times, t_stack *stacka, t_stack *stackb)
{
	t_stack	*chosen;
	while (times > 0)
	{
		if (ft_strncmp("sa", op, 4) == 0)
			sab(stacka, aorb);
		
		times--;
	}
}
