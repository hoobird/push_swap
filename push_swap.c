/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:11:26 by hulim             #+#    #+#             */
/*   Updated: 2024/04/17 03:01:34 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	if ((!isargsintandnodup(argc - 1, &argv[1]))
		|| setupstacks(&a, &b, argc - 1) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	populatestacka(&a, &argv[1], argc - 1);
	solve(&a, &b, argc -1);
	freestack(&a, &b);
	return (0);
}

void populatestacka(t_stack *stacka, char** numbersstr, int size)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		pushnum(stacka, ft_atoi(numbersstr[counter]));
		counter++;
	}
}

void	solve(t_stack *stacka, t_stack *stackb, int size)
{
	int	currtop;

	while (checkifsorted(stacka, size) == 1)
	{
		while (stacka->top > 0)
		{
			currtop = stacka->top;
			if (stacka->arr[currtop] > stacka->arr[currtop - 1])
				sab(stacka, 'a');
			pab(stacka, stackb, 'b');
		}
		while (stackb->top > 0)
		{
			currtop = stackb->top;
			if (stackb->arr[currtop] > stackb->arr[currtop - 1])
				sab(stackb, 'b');
			pab(stacka, stackb, 'a');
		}
		pab(stacka, stackb, 'a');
	}
}

int	checkifsorted(t_stack *stacka, int size)
{
	int	counter;

	counter = 0;

	while (counter < size - 2)
	{
		if (stacka->arr[counter] < stacka->arr[counter + 1])
			return (0);
	}
	if (stacka->top != size - 1);
		return (0);
	ft_printf("its sorted");
	return (1);
	
}