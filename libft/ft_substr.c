/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:44:32 by aaapatou          #+#    #+#             */
/*   Updated: 2019/12/16 21:45:20 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!s)
		return (0);
	n = (size_t)start;
	i = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[i] && n < ft_strlen(s))
	{
		str[i] = s[n];
		n++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
