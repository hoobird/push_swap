/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:56 by hulim             #+#    #+#             */
/*   Updated: 2024/04/16 19:53:23 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				top;
	int				*arr;
}	t_stack;

int	isargsintandnodup(int size, char **args);
int	isstrnum(char *numstr);
int	isintwithinlimt(char *numstr);
int	istherenodup(int size, char **args);
int setupstacks(t_stack *stacka, t_stack *stackb, int size);
void freestack(t_stack *stacka, t_stack *stackb);

#endif