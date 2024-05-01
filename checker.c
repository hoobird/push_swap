/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:23:16 by hulim             #+#    #+#             */
/*   Updated: 2024/05/01 15:28:39 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
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
	getandruninstructions(&a, &b);
}

void	getandruninstructions(t_stack *a, t_stack *b)
{
	char	*line;
	// int		ret;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		repeatops(line, 1, a, b);
		if (!line)
		{
			ft_putstr_fd("Error\n", 2);
			freestack(a, b);
			free(line);
			return ;
		}
		free(line);
	}
	if (checkifsorted(a, a->top + 1) == 1 && b->top == -1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	freestack(a, b);
	return ;
}