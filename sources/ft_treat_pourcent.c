/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:32:36 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:32:36 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_valid_caract(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' \
	|| c == 'x' || c == 'X' || c == '%' || c == 'p')
		return (1);
	return (0);
}

int	ft_check_valid_indicator(int c)
{
	if (c == '0' || c == '-' || c == '.' || c == '*')
		return (1);
	return (0);
}

int	countnumbers(long long n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int	ft_treat_pourcent(void)
{
	return (ft_count_putstr("%", 1));
}
