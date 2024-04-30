/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:23:16 by hulim             #+#    #+#             */
/*   Updated: 2024/04/30 20:15:27 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main()
{
	t_stack	a;
	t_stack	b;
	int		condition1;
	int		condition2;

	if (argc == 1)
		return (0);
	condition1 = !isargsintandnodup(argc - 1, &argv[1]);
	condition2 = setupstacks(&a, &b, argc - 1) == -1;
	if (condition1 || condition2)
	{
		ft_putstr_fd("Error\n", 2);
		freestack(&a, &b);
		return (0);
	}
	populatestacka(&a, &argv[1], argc - 1);
}
