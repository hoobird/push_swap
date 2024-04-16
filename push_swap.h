/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:36:56 by hulim             #+#    #+#             */
/*   Updated: 2024/04/16 13:22:51 by hulim            ###   ########.fr       */
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
	unsigned int	capacity;
	int				*array;
}	t_stack;

int	isargsintandnodup(int size, char **args);
int	isstrnum(char *numstr);
int	isintwithinlimt(char *numstr);
int	istherenodup(int size, char **args);

#endif