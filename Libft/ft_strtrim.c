/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:09:08 by hulim             #+#    #+#             */
/*   Updated: 2023/12/28 09:37:17 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	isset(char c, char const *set)
{
	int	counter;

	counter = 0;
	while (set[counter])
	{
		if (c == set[counter])
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*front;
	char	*back;
	char	*output;
	int		i;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	front = (char *) s1;
	back = front + ft_strlen(s1) - 1;
	while (*front && isset(*front, set))
		front++;
	while (*back && isset(*back, set))
		back--;
	if (back < front)
		return (ft_strdup(""));
	output = malloc(sizeof(char) * (back - front + 2));
	if (output == NULL)
		return (NULL);
	output[back - front + 1] = 0;
	i = 0;
	while (front <= back)
		output[i++] = *front++;
	return (output);
}
