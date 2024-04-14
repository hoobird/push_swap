/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:09:21 by hulim             #+#    #+#             */
/*   Updated: 2023/12/28 09:37:17 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*retval;

	length = ft_strlen(s1) + ft_strlen(s2);
	retval = malloc(sizeof(char) * (length + 1));
	if (retval && s1 && s2)
	{
		ft_strlcpy(retval, s1, ft_strlen(s1) + 1);
		ft_strlcat(retval, s2, length + 1);
		return (retval);
	}
	return (NULL);
}
