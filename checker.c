/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:23:16 by hulim             #+#    #+#             */
/*   Updated: 2024/04/20 15:23:40 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
