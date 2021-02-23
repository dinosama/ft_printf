/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:08:04 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 10:08:04 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_width(t_flags flags, int len)
{
	char	c;

	if (flags.zero == 1)
		c = '0';
	else
		c = ' ';
	while ((flags.width - len) > 0)
	{
		ft_putchar(c);
		flags.width--;
	}
}

int	ft_treatment(t_flags *flags, va_list *my_list)
{
	if (flags->type == 'c')
		return (ft_treat_character(*flags, my_list));
	else if (flags->type == 's')
		return (ft_treat_string(*flags, va_arg(*my_list, char *)));
	else if (flags->type == 'p')
		return (ft_treat_pointeur(flags, va_arg(*my_list, unsigned long long)));
	else if (flags->type == 'd')
		return (ft_treat_integer(flags, va_arg(*my_list, int)));
	else if (flags->type == 'i')
		return (ft_treat_integer(flags, va_arg(*my_list, int)));
	else if (flags->type == 'u')
		return (ft_treat_uinteger(flags, va_arg(*my_list, unsigned int)));
	else if (flags->type == 'x')
		return (ft_treat_hexa(flags, va_arg(*my_list, int), "0123456789abcdef"));
	else if (flags->type == 'X')
		return (ft_treat_hexa(flags, va_arg(*my_list, int), "0123456789ABCDEF"));
	else if (flags->type == '%')
		return (ft_treat_pourcent());
	ft_putchar('%');
	return (0);
}
