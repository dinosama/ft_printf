/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:10:45 by aaapatou          #+#    #+#             */
/*   Updated: 2021/03/04 20:35:45 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef	struct	s_flags
{
	int			already_print;
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			starpoint;
	int			nbnegat;
}				t_flags;

int				ft_count_putstr(char *str, int n);
void			ft_putlongnbr(long long nb);
void			ft_treat_width(t_flags flags, int len);
int				ft_treat_character(t_flags flags, va_list *my_list);
int				ft_treat_string(t_flags flags, char *str);
int				countnumbers(uintmax_t n, int base);
char			*ft_itoa_base(u_int64_t n, char *base);
int				ft_check_valid_caract(int c);
int				ft_check_valid_indicator(int c);
int				ft_isdigit(int c);
void			ft_flags_minus(t_flags *flags);
int				ft_flags_digit(const char *save, t_flags *flags);
int				ft_flags_point(const char *save, t_flags *flags,
				int i, va_list *my_list);
void			ft_flags_star(va_list *my_list,
				t_flags *flags);
int				ft_recup_flags(const char *save, t_flags *flags,
				int i, va_list *my_list);
int				ft_treat_pointeur(t_flags *flags, u_int64_t p);
int				ft_treat_integer(t_flags *flags, int n);
int				ft_treat_uinteger(t_flags *flags, unsigned int n);
int				ft_treat_hexa(t_flags *flags, long long n, char *hexa);
int				ft_treat_pourcent(t_flags *flags);
int				ft_treatment(t_flags *flags, va_list *my_list);
t_flags			ft_init_flags(void);
int				ft_print(va_list *my_list, const char *save, int final_length);
int				ft_printf(const char *src, ...);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strdup(const char *str);
void			ft_flags_zero(t_flags *flags);
int				ft_treat_uinteger_two(t_flags *flags, unsigned int n,
				int len, int zero);
int				ft_treat_integer_two(t_flags *flags, int n, int zero, int len);
int				ft_treat_hexa_two(t_flags *flags, char *str, int len, int zero);
int				ft_treat_pointeur_two(t_flags *flags, char *str,
				int zero, int len);
void			ft_treat_integer_three(t_flags *flags);

#endif
