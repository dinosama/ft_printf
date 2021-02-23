/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:30:18 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:30:18 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_pointeur(t_flags *flags, unsigned long long p)
{
	char	*str;
	int	final_lenght;
	int	len;
	int	zero;

	final_lenght = 0;
	zero = 0;
	str = ft_itoa_base(p, "0123456789abcdef");
	len = ft_strlen(str);
	if (flags->dot > len && flags->dot >= 0)
	{
		zero = flags->dot - len;
		len = flags->dot;
	}
	if (flags->minus == 0)
		ft_treat_width(*flags, (2 + len));
	final_lenght += ft_count_putstr("0x", 1);
	final_lenght += ft_count_putstr("0", zero);
	final_lenght += ft_count_putstr(str, 1);
	if (flags->minus == 1)
		ft_treat_width(*flags, (2 + len));
	if (flags->width > final_lenght)
		return (final_lenght + (flags->width - final_lenght));
	return (final_lenght);
}
