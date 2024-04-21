/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:09:38 by hulim             #+#    #+#             */
/*   Updated: 2024/04/22 05:23:01 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isargsintandnodup(int size, char **args)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		if (isstrnum(args[counter]) == 0 || isintwithinlimt(args[counter]) == 0)
			return (0);
		counter++;
	}
	return (istherenodup(size, args));
}

int	isstrnum(char *numstr)
{
	if (!(*numstr))
		return (0);
	if (*numstr == '-')
		numstr++;
	while (*numstr)
	{
		if (ft_isdigit(*numstr) == 0)
			return (0);
		numstr++;
	}
	return (1);
}

int	isintwithinlimt(char *numstr)
{
	int			multiplier;
	long		number;

	multiplier = 1;
	number = 0;
	if (*numstr == '-')
	{
		multiplier = -1;
		numstr++;
	}
	else if (*numstr == '+')
		numstr++;
	while (*numstr >= '0' && *numstr <= '9')
	{
		number = number * 10 + (*numstr - '0');
		numstr++;
	}
	number = number * multiplier;
	if (number < -2147483648 || number > 2147483647)
		return (0);
	return (1);
}

int	istherenodup(int size, char **args)
{
	int	counter;
	int	counter2;
	int	*intlist;

	intlist = malloc(sizeof(int) * size);
	counter = 0;
	while (counter < size)
	{
		intlist[counter] = ft_atoi(args[counter]);
		counter++;
	}
	counter = 0;
	while (counter < size - 1)
	{
		counter2 = counter + 1;
		while (counter2 < size)
		{
			if (intlist[counter] == intlist[counter2])
				return (0);
			counter2++;
		}
		counter++;
	}
	free(intlist);
	return (1);
}
