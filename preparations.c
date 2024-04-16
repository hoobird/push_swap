/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:39:56 by hulim             #+#    #+#             */
/*   Updated: 2024/04/17 03:05:17 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int setupstacks(t_stack *stacka, t_stack *stackb, int size)
{
    stacka->top = -1;
    stacka->arr = malloc(sizeof(int) * size);
    stackb->top = -1;
    stackb->arr = malloc(sizeof(int) * size);
    if (stacka->arr == NULL || stackb->arr == NULL)
        return (-1);
    return (0);
}

void freestack(t_stack *stacka, t_stack *stackb)
{
    if (stacka->arr != NULL)
        free(stacka->arr);
    if (stackb->arr != NULL)
        free(stackb->arr);
}
