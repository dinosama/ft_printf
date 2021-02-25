/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:56:19 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 10:56:19 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_count_putstr(char *str, int n)
{
	int	final_lenght;

	final_lenght = 0;
	final_lenght = n * ft_strlen(str);
	while (n > 0)
	{
		ft_putstr(str);
		n--;
	}
	return (final_lenght);
}
