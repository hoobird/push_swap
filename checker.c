/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:23:16 by hulim             #+#    #+#             */
/*   Updated: 2024/05/03 03:02:37 by hulim            ###   ########.fr       */
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

int	islinelegit(char* line)
{
	if (ft_strncmp(line, "sa", 4) == 0)
		return (1);
	if (ft_strncmp(line, "sb", 4) == 0)
		return (1);
	if (ft_strncmp(line, "ss", 4) == 0)
		return (1);
	if (ft_strncmp(line, "pa", 4) == 0)
		return (1);
	if (ft_strncmp(line, "pb", 4) == 0)
		return (1);
	if (ft_strncmp(line, "ra", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rb", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rr", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rra", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rrb", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rrr", 4) == 0)
		return (1);
	return (0);
}

void	cleanline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
}

void	getandruninstructions(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		cleanline(line);
		if (islinelegit(line) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			freestack(a, b);
			free(line);
			return ;
		}
		repeatops(line, 1, a, b);
		free(line);
	}
	if (checkifsorted(a, a->top + 1) == 1 && b->top == -1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	freestack(a, b);
	return ;
}
