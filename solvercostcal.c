/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvercostcal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 05:02:42 by hulim             #+#    #+#             */
/*   Updated: 2024/04/22 05:58:38 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkrotneeded(t_stack *from, t_stack *to, int findex)
{
	int	num;
	int	toclimbindex;
	int	tomaxindex;
	int	ttlsize;

	ttlsize = (from->top) + (to->top) + 2;
	toclimbindex = findminreturnindex(to);
	tomaxindex = findmaxreturnindex(to);
	num = from->arr[findex];
	while (toclimbindex != tomaxindex)
	{
		if (num < to->arr[toclimbindex])
			return (((from->top) - findex) * ttlsize + ((to->top) - toclimbindex
					+ 1));
		if (toclimbindex == to->top)
			toclimbindex = 0;
		else
			toclimbindex++;
	}
	if (num < to->arr[tomaxindex])
		return (((from->top) - findex) * ttlsize + (to->top) + 1 - tomaxindex);
	else
		return (((from->top) - findex) * ttlsize + (to->top) - tomaxindex);
}

int	*findminrotindex(int *rotlist, int sizefrom, int sizeto)
{
	int	rotlistcounter;
	int	currfrom;
	int	currto;
	int	minmoves;
	int	*output;

	output = ft_calloc(sizeof(int), 2);
	minmoves = sizefrom + sizeto;
	rotlistcounter = sizefrom - 1;
	while (rotlistcounter >= 0)
	{
		currfrom = rotlist[rotlistcounter] / (sizefrom + sizeto);
		currto = rotlist[rotlistcounter] % (sizefrom + sizeto);
		if (currfrom > (sizefrom / 2))
			currfrom = currfrom - sizefrom;
		if (currto > (sizeto / 2))
			currto = currto - sizeto;
		updateminmoves(currfrom, currto, &minmoves, output);
		rotlistcounter--;
	}
	return (output);
}

void	updateminmoves(int currfrom, int currto, int *minmoves, int *output)
{
	if ((currfrom < 0 && currto < 0) || (currfrom > 0 && currto > 0))
	{
		if (findmax2(positiveit(currfrom), positiveit(currto)) < *minmoves)
		{
			*minmoves = findmax2(positiveit(currfrom), positiveit(currto));
			output[0] = currfrom;
			output[1] = currto;
		}
	}
	else if (positiveit(currfrom) + positiveit(currto) < *minmoves)
	{
		*minmoves = positiveit(currfrom) + positiveit(currto);
		output[0] = currfrom;
		output[1] = currto;
	}
}

void	findlowestcostmove(t_stack *from, t_stack *to)
{
	int	indexchecking;
	int	*fromtorotations;
	int	*bestchoice;

	fromtorotations = ft_calloc(sizeof(int), (from->top) + 1);
	indexchecking = from->top;
	while (indexchecking >= 0)
	{
		fromtorotations[indexchecking] = checkrotneeded(from, to,
				indexchecking);
		indexchecking--;
	}
	bestchoice = findminrotindex(fromtorotations, (from->top) + 1,
			(to->top) + 1);
	moveupdown(from, to, bestchoice);
	pab(from, to, "b");
	free(bestchoice);
	free(fromtorotations);
}
