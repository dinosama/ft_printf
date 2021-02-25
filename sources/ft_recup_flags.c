/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:08:35 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 10:08:35 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_flags_minus(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 1;
}

int		ft_flags_digit(const char *save, t_flags *flags)
{
	flags->width = ft_atoi((char*)save);
	return (countnumbers(flags->width, 10));
}

int		ft_flags_point(const char *save, t_flags *flags,
		int i, va_list *my_list)
{
	i++;
	if (save[i] == '*')
	{
		flags->starpoint = 1;
		flags->dot = va_arg(*my_list, int);
		if (flags->dot < 0)
			flags->dot = -1;
		return (i);
	}
	flags->dot = 0;
	while (ft_isdigit(save[i]))
	{
		flags->dot = (flags->dot * 10) + (save[i] - 48);
		i++;
	}
	return (i - 1);
}

void	ft_flags_star(va_list *my_list, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(*my_list, int);
	if (flags->width < 0)
	{
		flags->zero = 0;
		flags->minus = 1;
		flags->width = flags->width * (-1);
	}
}

int		ft_recup_flags(const char *save, t_flags *flags,
		int i, va_list *my_list)
{
	int	stock;

	stock = i;
	while (save[i])
	{
		if (save[i] == '0' && flags->width == -1)
			ft_flags_zero(flags);
		else if (save[i] == '-' && flags->width == -1)
			ft_flags_minus(flags);
		else if (ft_isdigit(save[i]) && flags->star == 0 && flags->width == -1)
			i = (i - 1) + ft_flags_digit(&save[i], flags);
		else if (save[i] == '.')
			i = ft_flags_point(save, flags, i, my_list);
		else if (save[i] == '*' && flags->width == -1 && flags->starpoint == 0)
			ft_flags_star(my_list, flags);
		else if (ft_check_valid_caract(save[i]) && stock != i)
		{
			flags->type = save[i];
			return (i);
		}
		else if (stock != i)
			return (stock);
		i++;
	}
	return (i);
}
