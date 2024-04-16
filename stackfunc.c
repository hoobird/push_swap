/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:16:18 by hulim             #+#    #+#             */
/*   Updated: 2024/04/16 19:49:56 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushnum(t_stack *stack1, int num)
{
	stack1->top++;
	stack1->arr[top] = num;
}

int	popnum(t_stack *stack1)
{
	int	popped;

	popped = stack1->arr[stack1->top];
	stack1->top--;
	return (popped);
}
