/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:11:26 by hulim             #+#    #+#             */
/*   Updated: 2024/04/19 23:24:01 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack *stacka, t_stack *stackb)
{
	int	largestindex;

	largestindex = stacka->top;
	ft_printf("TOPA->");
	while (largestindex >= 0)
	{
		ft_printf("%d ", stacka->arr[largestindex]);
		largestindex--;
	}
	ft_printf("<-BOTTOMA\t");
	largestindex = stackb->top;
	ft_printf("TOPB->");
	while (largestindex >= 0)
	{
		ft_printf("%d ", stackb->arr[largestindex]);
		largestindex--;
	}
	ft_printf("<-BOTTOMB\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		condition1;
	int		condition2;

	if (argc == 1)
		return (0);
	condition1 = !isargsintandnodup(argc - 1, &argv[1]);
	condition2 = setupstacks(&a, &b, argc - 1) == -1;
	if (condition1 || condition2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	populatestacka(&a, &argv[1], argc - 1);
	solve(&a, &b);
	freestack(&a, &b);
	return (0);
}

void	solve(t_stack *stacka, t_stack *stackb)
{
	int	splitcounter;
	int	currtop;
	int	minnum;
	int	maxnum;

	while (stacka->top >= 0)
	{
		while (splitcounter > 0 && stacka->top >= 0)
		{
			currtop = stacka->top;
			minnum = stacka->arr[findminreturnindexrange(stacka, splitcounter)];
			while (stacka->arr[currtop] != minnum)
			{
				rab(stacka, "a");
			}
			pab(stacka, stackb, "b");
			splitcounter--;
		}
		splitcounter = 20;
	}
	while (stackb->top >= 0)
	{
		currtop = stackb->top;
		maxnum = stackb->arr[findmaxreturnindex(stackb)];
		while (stackb->arr[currtop] != maxnum)
			rab(stackb, "b");
		pab(stacka, stackb, "a");
	}
	// printstack(stacka, stackb);
	// if (checkifsorted(stacka, 5) == 1)
	// 	ft_printf("sorted");
}

int	checkifsorted(t_stack *stacka, int size)
{
	int	counter;

	counter = 0;
	while (counter < size - 1)
	{
		if (stacka->arr[counter] < stacka->arr[counter + 1])
			return (0);
		counter++;
	}
	if (stacka->top != size - 1)
		return (0);
	return (1);
}
