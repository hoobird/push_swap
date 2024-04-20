/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:11:26 by hulim             #+#    #+#             */
/*   Updated: 2024/04/21 00:21:12 by hulim            ###   ########.fr       */
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

int	checkrotneeded(t_stack *from, t_stack *to, int findex)
{
	int	num;
	int	toclimbindex;
	int	tomaxindex;
	int	ttlsize;

	ttlsize = from->top + to->top + 2;
	toclimbindex = findminreturnindex(to);
	tomaxindex = findmaxreturnindex(to);
	num = from->arr[findex];
	while (toclimbindex != tomaxindex)
	{
		if (num < to->arr[toclimbindex])
			return (((from->top) - findex) * ttlsize + (to->top) - toclimbindex);
		if(toclimbindex == to->top)
			toclimbindex = 0;
		else
			toclimbindex++;
	}
	if (num < to->arr[tomaxindex])
		return (((from->top) - findex) * ttlsize + (to->top) - tomaxindex);
	else
		return (((from->top) - findex) * ttlsize + (to->top) - tomaxindex + 1);
}

int	positiveit(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int	findmax2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	findmin2(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	*findminrotindex(int *rotlist, int sizefrom, int sizeto)
{
	int	rotlistcounter;
	int	currfrom;
	int currto;
	int minmoves;
	int	*output;

	output = malloc(sizeof(int) * 2);
	minmoves = sizefrom + sizeto;
	rotlistcounter = sizefrom;
	while(rotlistcounter > 0)
	{
		currfrom = rotlist[rotlistcounter] / (sizefrom + sizeto);
		currto = rotlist[rotlistcounter] % (sizefrom + sizeto);
		if (currfrom < (sizefrom / 2))
			currfrom = -(sizefrom - currfrom);
		if (currto < (sizeto / 2))
			currto = -(sizeto - currfrom);
		if ((currfrom < 0 && currto < 0 ) || (currfrom > 0 && currto > 0))
		{
			if (positiveit((currfrom) - positiveit(currto)) < minmoves)
			{
				minmoves = positiveit((currfrom) - positiveit(currto));
				output[0] = currfrom;
				output[1] = currto;
			}
		}
		else if(positiveit(currfrom) + positiveit(currto) < minmoves)
		{
			minmoves = positiveit(currfrom) + positiveit(currto);
			output[0] = currfrom;
			output[1] = currto;	
		}
		rotlistcounter--;
	}	
	return (output);
}

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
		bestchoice[0] += commonsteps;
		bestchoice[1] += commonsteps;
		while (commonsteps != 0)
		{
			rrr(stacka, stackb);
			commonsteps++;
		}
	}
	ft_printf("BESTCHOCE->a:%d, b:%d",bestchoice[0],bestchoice[1]);
	int fked = 10;
	while (bestchoice[0] < 0)
	{
		rrab(stacka, "a");
		bestchoice[0]++;
		fked--;
		if (fked == 0)
			break;
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
		fked--;
		if (fked == 0)
			break;
	}
	while (bestchoice[1] > 0)
	{
		rab(stackb, "b");
		bestchoice[1]--;
	}
	
}

void findlowestcostmove(t_stack *from, t_stack *to)
{
	int indexchecking;
	int	*fromtorotations;
	int	*bestchoice;

	fromtorotations = malloc(sizeof(int) * ((from->top) + 1));
	indexchecking = from -> top;
	while (indexchecking > 0)
	{
		fromtorotations[indexchecking] = checkrotneeded(from, to, indexchecking);
		indexchecking--;
	}
	printstack(from, to);
	bestchoice = findminrotindex(fromtorotations, (from->top) + 1, (to->top) + 1);
	ft_printf("BC from: %d, to: %d\n", bestchoice[0], bestchoice[1]);
	moveupdown(from, to, bestchoice);
	printstack(from, to);
	sleep(1);
	pab(from, to, "b");
	free(bestchoice);
	free(fromtorotations);
}

void	solveusingcost(t_stack *stacka, t_stack *stackb)
{
	
	pab(stacka, stackb, "b");
	pab(stacka, stackb, "b");
	while (stacka->top >= 0)
		findlowestcostmove(stacka, stackb);
	while (stackb->top >= 0)
		pab(stacka, stackb, "a");
	printstack(stacka, stackb);
}

void	solve(t_stack *stacka, t_stack *stackb, int size)
{
	if (size == 2)
		solve2(stacka, "a");
	if (size == 3)
		solve3(stacka, "a");
	if (size > 3)
		solveusingcost(stacka, stackb);
	printstack(stacka, stackb);
}

void	solve2(t_stack *stack1, char *aorb)
{
	int	minindex;
	
	minindex = findminreturnindex(stack1);
	if (minindex != 1)
		sab(stack1, aorb);
}

void	solve3(t_stack *stack1, char *aorb)
{
	int minindex;
	int maxindex;

	minindex = findminreturnindex(stack1);
	maxindex = findmaxreturnindex(stack1);
	if (minindex == 0)
	{
		if (maxindex == 1)
			rrab(stack1, aorb);
		else
		{
			rab(stack1, aorb);
			sab(stack1, aorb);
		}
	}
	else if (minindex == 1)
	{
		if (maxindex == 2)
			rab(stack1, aorb);
		else
			sab(stack1, aorb);
	} 
	else
		if (maxindex == 1)
		{
			sab(stack1, aorb);
			rab(stack1, aorb);
		}	
}
