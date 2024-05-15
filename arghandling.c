/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arghandling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:53:47 by hulim             #+#    #+#             */
/*   Updated: 2024/05/15 17:54:42 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copyfromargv(char **argv, int argc)
{
	int		i;
	char	**numstr;

	numstr = ft_calloc(sizeof(char *), (argc));
	i = 0;
	while (i < argc - 1)
	{
		numstr[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	return (numstr);
}

void	freenumstr(char **numstr)
{
	int	i;

	i = 0;
	while (numstr[i])
	{
		free(numstr[i]);
		i++;
	}
	free(numstr);
}

int	getstrstrsize(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
