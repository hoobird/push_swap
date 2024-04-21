/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:12:49 by hulim             #+#    #+#             */
/*   Updated: 2024/04/22 06:54:20 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack *stack1, char *aorb)
{
	int		temp;
	int		topindex;
	char	*output;

	if (stack1->top < 1)
		return ;
	topindex = stack1->top;
	temp = stack1->arr[topindex];
	stack1->arr[topindex] = stack1->arr[topindex - 1];
	stack1->arr[topindex - 1] = temp;
	if (aorb != 0)
	{
		output = ft_strjoin("s", aorb);
		ft_putstr_fd(output, 1);
		ft_putchar_fd('\n', 1);
		free(output);
	}
}

void	ss(t_stack *stacka, t_stack *stackb)
{
	sab(stacka, 0);
	sab(stackb, 0);
	ft_putstr_fd("ss", 1);
}

void	pab(t_stack *stacka, t_stack *stackb, char *aorb)
{
	int		popped;
	char	*output;

	if (ft_strncmp(aorb, "a", 1) == 0)
	{
		popped = popnum(stackb);
		pushnum(stacka, popped);
	}
	else
	{
		popped = popnum(stacka);
		pushnum(stackb, popped);
	}
	output = ft_strjoin("p", aorb);
	ft_putstr_fd(output, 1);
	ft_putchar_fd('\n', 1);
	free(output);
}
