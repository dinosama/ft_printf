/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:27:12 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:27:12 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_character(t_flags flags, va_list *my_list)
{
	char	c;
	int	final_length;

	if (flags.width > 1)
		final_length = flags.width;
	else
		final_length = 1;
	c = va_arg(*my_list, int);
	if (flags.minus == 0)
		ft_treat_width(flags, 1);
	write(1, &c, 1);
	if (flags.minus == 1)
		ft_treat_width(flags, 1);
	return (final_length);
}
