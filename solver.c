/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 04:19:34 by hulim             #+#    #+#             */
/*   Updated: 2024/04/22 05:51:58 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve2(t_stack *stack1, char *aorb)
{
	int	minindex;

	minindex = findminreturnindex(stack1);
	if (minindex != 1)
		sab(stack1, aorb);
}

void	solve3(t_stack *stack1, char *aorb)
{
	if (findminreturnindex(stack1) == 0)
	{
		if (findmaxreturnindex(stack1) == 1)
			rrab(stack1, aorb);
		else
		{
			rab(stack1, aorb);
			sab(stack1, aorb);
		}
	}
	else if (findminreturnindex(stack1) == 1)
	{
		if (findmaxreturnindex(stack1) == 2)
			rab(stack1, aorb);
		else
			sab(stack1, aorb);
	}
	else if (findmaxreturnindex(stack1) == 1)
	{
		sab(stack1, aorb);
		rab(stack1, aorb);
	}
}

void	solve5(t_stack *stacka, t_stack *stackb)
{
	int	move;
	int	count;

	count = 2;
	while (count > 0)
	{
		if (findminreturnindex(stacka) > 1)
			move = stacka->top - findminreturnindex(stacka);
		else
			move = -1 - findminreturnindex(stacka);
		while (move != 0)
		{
			if (move > 0)
				rab(stacka, "a");
			if (move < 0)
				rrab(stacka, "a");
			getcloserto0(&move);
		}
		pab(stacka, stackb, "b");
		count--;
	}
	solve3(stacka, "a");
	repeatops("pa", 2, stacka, stackb);
}

void	solveusingcost(t_stack *stacka, t_stack *stackb)
{
	int	dir;

	pab(stacka, stackb, "b");
	pab(stacka, stackb, "b");
	while (stacka->top >= 0)
		findlowestcostmove(stacka, stackb);
	while (stackb->top >= 0)
		pab(stacka, stackb, "a");
	if (findmaxreturnindex(stacka) > (stacka->top) / 2)
		dir = 1;
	while (findmaxreturnindex(stacka) != 0)
	{
		if (dir == 1)
			rab(stacka, "a");
		else
			rrab(stacka, "a");
	}
}
