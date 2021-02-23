/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:42:15 by aaapatou          #+#    #+#             */
/*   Updated: 2019/12/16 21:45:20 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	while ((size_t)i < n)
	{
		str[i] = str2[i];
		if (str[i] == (unsigned char)c)
			return ((void*)&dest[i + 1]);
		i++;
	}
	return (NULL);
}
