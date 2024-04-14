/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:58:39 by hoobird           #+#    #+#             */
/*   Updated: 2023/12/28 09:36:46 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putint(int i)
{
	char	*str;
	int		val;

	str = ft_itoa(i);
	val = ft_putstr(str);
	free(str);
	return (val);
}
