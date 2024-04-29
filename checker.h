/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:58:46 by hulim             #+#    #+#             */
/*   Updated: 2024/04/30 01:09:53 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				top;
	int				*arr;
}	t_stack;

#endif