/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:16:18 by hulim             #+#    #+#             */
/*   Updated: 2024/04/18 21:26:00 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushnum(t_stack *stack1, int num)
{
	int topindex;

	topindex = stack1->top;
	stack1->top = topindex + 1;
	stack1->arr[topindex + 1] = num;
}

int	popnum(t_stack *stack1)
{
	int	popped;

	popped = stack1->arr[stack1->top];
	stack1->top--;
	return (popped);
}

int	findmaxreturnindex(t_stack *stack1)
{
	int	indexcounter;
	int largestnum;
	int	largestindex;

	indexcounter = stack1->top;
	largestnum = stack1->arr[0];
	largestindex = 0;
	while (indexcounter > 0)
	{
		if (stack1->arr[indexcounter] > largestnum)
		{
			largestindex = indexcounter;
			largestnum = stack1->arr[indexcounter];
		}
		indexcounter--;
	}
	return largestindex;
}

int	findminreturnindex(t_stack *stack1)
{
	int	indexcounter;
	int smallestnum;
	int	smallestindex;

	indexcounter = stack1->top;
	smallestnum = stack1->arr[0];
	smallestindex = 0;
	while (indexcounter > 0)
	{
		if (stack1->arr[indexcounter] < smallestnum)
		{
			smallestindex = indexcounter;
			smallestnum = stack1->arr[indexcounter];
		}
		indexcounter--;
	}
	return smallestindex;
}

int	findminreturnindexrange(t_stack *stack1, int range)
{
	int	indexcounter;
	int lowernum;
	int	lowerindex;

	indexcounter = stack1->top;
	lowerindex = (stack1->top) - range;
	if (lowerindex < 0)
		lowerindex = 0;
	lowernum = stack1->arr[lowerindex];
	while (indexcounter > lowerindex)
	{
		if (stack1->arr[indexcounter] < lowernum)
		{
			lowerindex = indexcounter;
			lowernum = stack1->arr[indexcounter];
		}
		indexcounter--;
	}
	return lowerindex;
}