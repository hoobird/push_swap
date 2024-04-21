/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:05:30 by hulim             #+#    #+#             */
/*   Updated: 2024/04/22 05:59:51 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moveupdown(t_stack *stacka, t_stack *stackb, int *bestchoice)
{
	int	commonsteps;

	if (bestchoice[0] > 0 && bestchoice[1] > 0)
	{
		commonsteps = findmin2(bestchoice[0], bestchoice[1]);
		bestchoice[0] -= commonsteps;
		bestchoice[1] -= commonsteps;
		while (commonsteps != 0)
		{
			rr(stacka, stackb);
			commonsteps--;
		}
	}
	else if (bestchoice[0] < 0 && bestchoice[1] < 0)
	{
		commonsteps = findmax2(bestchoice[0], bestchoice[1]);
		bestchoice[0] -= commonsteps;
		bestchoice[1] -= commonsteps;
		while (commonsteps != 0)
		{
			rrr(stacka, stackb);
			commonsteps++;
		}
	}
	noncommonsteps(stacka, stackb, bestchoice);
}

void	noncommonsteps(t_stack *stacka, t_stack *stackb, int *bestchoice)
{
	while (bestchoice[0] < 0)
	{
		rrab(stacka, "a");
		bestchoice[0]++;
	}
	while (bestchoice[1] < 0)
	{
		rrab(stackb, "b");
		bestchoice[1]++;
	}
	while (bestchoice[0] > 0)
	{
		rab(stacka, "a");
		bestchoice[0]--;
	}
	while (bestchoice[1] > 0)
	{
		rab(stackb, "b");
		bestchoice[1]--;
	}
}
