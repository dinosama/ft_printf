/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:17:15 by aaapatou          #+#    #+#             */
/*   Updated: 2021/03/06 14:23:28 by aaapatou         ###   ########.fr       */
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

void	ft_treat_integer_three(t_flags *flags)
{
	if (flags->dot > -1)
		flags->zero = 0;
}

int		ft_treat_integer_two(t_flags *flags, int n, int zero, int len)
{
	if (flags->nbnegat == 1)
		len++;
	if (flags->nbnegat == 1 && flags->zero == 1 && flags->dot == -1 \
	&& flags->minus == 0)
	{
		if (n != -2147483648)
			ft_putchar('-');
		else
			len--;
	}
	if (flags->minus == 0)
		ft_treat_width(*flags, len);
	if (flags->nbnegat == 1 && flags->zero == 0 && n != -2147483648)
		ft_putchar('-');
	else if (n == -2147483648)
		len--;
	ft_count_putstr("0", zero);
	if (n != 0 || flags->dot != 0)
		ft_putlongnbr((long long)n);
	else
		len = 0;
	if (flags->minus == 1)
		ft_treat_width(*flags, len);
	return (len);
}

int		ft_treat_integer(t_flags *flags, int n)
{
	int	len;
	int	zero;

	len = 0;
	zero = 0;
	if (n < 0)
	{
		n = -n;
		flags->nbnegat = 1;
	}
	len += countnumbers(n, 10);
	ft_treat_integer_three(flags);
	if (flags->dot > len)
	{
		zero = flags->dot - len;
		len = flags->dot;
	}
	if (n == 0 && flags->dot == 0)
		len--;
	len = ft_treat_integer_two(flags, n, zero, len);
	if (n == -2147483648 && flags->zero == 1)
		len++;
	if (flags->width > len)
		return (len + (flags->width - len));
	return (len);
}
