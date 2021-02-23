/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:27:55 by aaapatou          #+#    #+#             */
/*   Updated: 2021/02/12 11:27:55 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_string(t_flags flags, char  *str)
{
	int	len;

	len = ft_strlen(str);
	if (flags.dot < len && flags.dot != -1)
		len = flags.dot;
	if (flags.minus == 0)
		ft_treat_width(flags, len);
	write(1, str, len);
	if (flags.minus == 1)
		ft_treat_width(flags, len);
	if (flags.width < len)
		return (len);
	return (len + (flags.width - len));
}