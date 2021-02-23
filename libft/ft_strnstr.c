/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:44:15 by aaapatou          #+#    #+#             */
/*   Updated: 2019/12/16 21:45:20 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	int		i;
	int		i2;

	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0' && (size_t)i < l)
	{
		i2 = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + i2] == needle[i2] && needle[i2] != '\0' &&
					(size_t)(i + i2) < l)
				i2++;
			if (needle[i2] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (0);
}
