/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pourcent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:32:36 by aaapatou          #+#    #+#             */
/*   Updated: 2021/03/04 20:35:57 by aaapatou         ###   ########.fr       */
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

int	countnumbers(uintmax_t n, int base)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

int	ft_treat_pourcent(t_flags *flags)
{
	int	final_length;

	if (flags->width > 1)
		final_length = flags->width;
	else
		final_length = 1;
	if (flags->minus == 0)
		ft_treat_width(*flags, 1);
	ft_count_putstr("%", 1);
	if (flags->minus == 1)
		ft_treat_width(*flags, 1);
	return (final_length);
}
