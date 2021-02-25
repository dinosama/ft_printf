/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:08:58 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 10:08:58 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.starpoint = 0;
	flags.type = 0;
	flags.width = -1;
	flags.zero = 0;
	flags.nbnegat = 0;
	return (flags);
}

int			ft_print(va_list *my_list, const char *save, int final_length)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (save[i])
	{
		flags = ft_init_flags();
		if (save[i] != '%')
		{
			ft_putchar(save[i]);
			final_length++;
		}
		else
		{
			i = ft_recup_flags(save, &flags, i, my_list);
			final_length = final_length + ft_treatment(&flags, my_list);
		}
		i++;
	}
	return (final_length);
}

int			ft_printf(const char *src, ...)
{
	va_list		my_list;
	const char	*save;
	int			final_length;

	final_length = 0;
	save = ft_strdup(src);
	va_start(my_list, src);
	final_length = ft_print(&my_list, save, final_length);
	free((char*)save);
	va_end(my_list);
	return (final_length);
}
