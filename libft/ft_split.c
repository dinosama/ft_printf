/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 21:43:17 by aaapatou          #+#    #+#             */
/*   Updated: 2019/12/16 21:45:20 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char		*ft_strncapy(char *dest, char const *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*ft_strduper(char const *str, char c)
{
	char	*s;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (0);
	s = ft_strncapy(s, str, i);
	return (s);
}

static char		**ft_represailles(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	size = countwords(s, c);
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (0);
	tab[size] = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			if (!(tab[size] = ft_strduper((s + i), c)))
				return (ft_represailles(tab));
		size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}
