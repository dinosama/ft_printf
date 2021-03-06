/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:31:07 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:31:07 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_uinteger_two(t_flags *flags, unsigned int n, int len, int zero)
{
	if (n == 0 && flags->dot == 0)
		len--;
	if (flags->minus == 0)
		ft_treat_width(*flags, len);
	ft_count_putstr("0", zero);
	if (n != 0 || flags->dot != 0)
		ft_putlongnbr((long long)n);
	if (flags->minus == 1)
		ft_treat_width(*flags, len);
	return (len);
}

int	ft_treat_uinteger(t_flags *flags, unsigned int n)
{
	int	len;
	int	zero;

	zero = 0;
	n = n % 4294967296;
	len = countnumbers((unsigned long long)n, 10);
	if (flags->dot != -1)
		flags->zero = 0;
	if (flags->dot > len)
	{
		zero = flags->dot - len;
		len = flags->dot;
	}
	len = ft_treat_uinteger_two(flags, n, len, zero);
	if (n == 0 && flags->dot == 0 && flags->width < 1)
		return (0);
	if (flags->width > len)
		return (len + (flags->width - len));
	return (len);
}
