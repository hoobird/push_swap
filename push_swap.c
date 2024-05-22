/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:11:26 by hulim             #+#    #+#             */
/*   Updated: 2024/05/22 16:19:01 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		condition1;
	int		condition2;
	char	**numstr;

	if (argc == 1)
		return (0);
	if (argc == 2)
		numstr = ft_split(argv[1], ' ');
	else
		numstr = copyfromargv(argv, argc);
	condition1 = !isargsintandnodup(getstrstrsize(numstr), numstr);
	condition2 = setupstacks(&a, &b, getstrstrsize(numstr)) == -1;
	if (condition1 || condition2)
		ft_putstr_fd("Error\n", 2);
	else
	{
		populatestacka(&a, numstr, getstrstrsize(numstr));
		solve(&a, &b, getstrstrsize(numstr));
	}
	freestack(&a, &b);
	freenumstr(numstr);
	return (0);
}

void	solve(t_stack *stacka, t_stack *stackb, int size)
{
	if (checkifsorted(stacka, size))
		return ;
	if (size == 2)
		solve2(stacka, "a");
	else if (size <= 8)
		solvesmall(stacka, stackb);
	else if (size > 8)
		solveusingcost(stacka, stackb);
}
