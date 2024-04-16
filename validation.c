/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:09:38 by hulim             #+#    #+#             */
/*   Updated: 2024/04/16 12:51:24 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isargsint(int size, char **args)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		if (isstrnum(args[counter]) == 0 || isintwithinlimt(args[counter]) == 0)
			return (0);
		counter++;
	}
	return (1);
}

int	isstrnum(char *numstr)
{
	if (!(*numstr))
		return (0);
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
	int		multiplier;
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

int istheredup(int size, char **args)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		
	}
}