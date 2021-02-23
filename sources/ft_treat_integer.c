/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:17:15 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:17:15 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putlongnbr(long long nb)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putlongnbr(nb / 10);
		ft_putlongnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int	ft_treat_integer_two(t_flags *flags, int n, int zero, int len, int negat)
{
	if (flags->minus == 0)
		ft_treat_width(*flags, len);
	if (negat == 1)
		ft_putchar('-');
	ft_count_putstr("0", zero);
	ft_putlongnbr((long long)n);
	if (negat == 1)
		len++;
	if (flags->minus == 1)
		ft_treat_width(*flags, len);
	return (len);
}

int	ft_treat_integer(t_flags *flags, int n)
{
	int	len;
	int	zero;
	int	negat;

	negat = 0;
	len = 0;
	zero = 0;
	if (n < 0)
	{
		n = -n;
		negat = 1;
	}
	len += countnumbers(n, 10);
	if (flags->dot > -1)
		flags->zero = 0;
	if (flags->dot > len)
	{
		zero = flags->dot - len;
		len = flags->dot;
	}
	len = ft_treat_integer_two(flags, n, zero, len, negat);
	if (flags->width > len)
		return (len + (flags->width - len));
	return (len);
}
