/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:31:53 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:31:53 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char	*str;
	int	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = countnumbers((unsigned long long)n, 16);
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size] = '\0';
	while (size != 0)
	{
		str[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (str);
}

int		ft_treat_hexa_two(t_flags *flags, unsigned int n, int len, int zero)
{
	int		final_lenght;

	final_lenght = 0;
	if (flags->minus == 0)
		ft_treat_width(*flags, (len));
	final_lenght += ft_count_putstr("0", zero);
	final_lenght += ft_count_putstr(str, 1);
	if (flags->minus == 1)
		ft_treat_width(*flags, (len));
	return (final_lenght);
}

int		ft_treat_hexa(t_flags *flags, unsigned int n, char *hexa)
{
	char	*str;
	int	final_lenght;
	int	len;
	int	zero;

	n = (unsigned int)(4294967295 + 1 + n);
	zero = 0;
	str = ft_itoa_base(n, hexa);
	len = ft_strlen(str);
	if (flags->dot > len && flags->dot >= 0)
	{
		zero = flags->dot - len;
		len = flags->dot;
	}
	if (flags->dot > -1)
		flags->zero = 0;
	final_lenght = ft_treat_hexa_two(flags, n, len, zero);
	if (flags->width > final_lenght)
		return (final_lenght + (flags->width - final_lenght));
	return (final_lenght);
}
