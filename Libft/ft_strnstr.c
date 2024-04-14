/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:17:18 by hulim             #+#    #+#             */
/*   Updated: 2023/12/28 09:37:17 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (*needle == 0)
		return ((char *) haystack);
	h = 0;
	while (haystack[h] != 0 && h < len)
	{
		n = 0;
		while (haystack[h + n] == needle[n] && h + n < len)
		{
			if (needle[n + 1] == 0)
				return ((char *)(&haystack[h]));
			n++;
		}
		h++;
	}
	return (0);
}
