/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:30:18 by aaapatou          #+#    #+#             */
/*   Updated: 2021/03/04 16:27:19 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_pointeur_two(t_flags *flags, char *str, int zero, int len)
{
	int		final_lenght;

	final_lenght = 0;
	if (flags->minus == 0)
		ft_treat_width(*flags, (2 + len));
	final_lenght += ft_count_putstr("0x", 1);
	final_lenght += ft_count_putstr("0", zero);
	if (str[0] != '0' || flags->dot != 0)
		final_lenght += ft_count_putstr(str, 1);
	if (flags->minus == 1)
		ft_treat_width(*flags, (2 + len));
	return (final_lenght);
}

int	ft_treat_pointeur(t_flags *flags, uint64_t p)
{
	char	*str;
	int		final_lenght;
	int		len;
	int		zero;

	p = (unsigned long long)(18446744073709551615 + 1 + p);
	zero = 0;
	str = ft_itoa_base(p, "0123456789abcdef");
	len = ft_strlen(str);
	if (p == 0 && flags->dot == 0)
		len = 0;
	if (flags->dot > len && flags->dot >= 0)
	{
		zero = flags->dot - len;
		len = flags->dot;
	}
	final_lenght = ft_treat_pointeur_two(flags, str, zero, len);
	free(str);
	if (flags->width > final_lenght)
		return (final_lenght + (flags->width - final_lenght));
	return (final_lenght);
}
