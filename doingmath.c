/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doingmath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:49:15 by hulim             #+#    #+#             */
/*   Updated: 2024/04/22 06:02:49 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	getcloserto0(int *a)
{
	if (*a > 0)
		*a = *a - 1;
	else
		*a = *a + 1;
}
