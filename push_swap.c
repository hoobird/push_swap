/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:11:26 by hulim             #+#    #+#             */
/*   Updated: 2024/04/18 19:32:22 by hulim            ###   ########.fr       */
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
	solve(&a, &b, argc - 1);
	freestack(&a, &b);
	return (0);
}

void	solve(t_stack *stacka, t_stack *stackb, int size)
{
	int	currtop;
	int minormaxbool;
	int	minormaxnumber;
	int	upordownbool;

	while (checkifsorted(stacka, size) == 0)
	{
		while (stacka->top >= 0)
			pab(stacka, stackb, "b");
		while (stackb->top >= 0)
		{
			currtop = stackb->top;
			if (findminreturnindex(stackb) > findmaxreturnindex(stackb))
			{
				minormaxbool = 0;
				upordownbool = findminreturnindex(stackb) + 1 > (currtop + 1) / 2;
				minormaxnumber = stackb->arr[findminreturnindex(stackb)];
			}
			else
			{
				minormaxbool = 1;
				upordownbool = findmaxreturnindex(stackb) + 1 > (currtop + 1) / 2;
				minormaxnumber = stackb->arr[findmaxreturnindex(stackb)];
			}
			while (stackb->arr[currtop] != minormaxnumber)
			{
				if (upordownbool == 1)
					rab(stackb, "a");
				else
					rrab(stackb, "a");
			}
			pab(stacka, stackb, "a");
			if (minormaxbool == 0)
				rab(stacka, "a");
			// printstack(stacka, stackb);
		}
		rrab(stacka, "a");
		// printstack(stacka, stackb);
		// rab(stacka,"a");
	}
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
