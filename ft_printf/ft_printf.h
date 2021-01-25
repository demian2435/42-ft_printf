/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:24:19 by dmalori           #+#    #+#             */
/*   Updated: 2021/01/25 12:19:35 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int minus;
	int size;
	int terminator;
	int point;
	int zero;
}				t_flags;

int				ft_printf(const char *str, ...);
int				ft_isdigit(int c);
int				ft_strlen(const char *s);
int				ft_toupper(int c);
char			*ft_toupperstr(char *str);
int				ft_putlchar(char c);
int				ft_putlstr(char *str, int len);
int				ft_isterminator(int c);
t_flags			ft_initflags(t_flags flags);
int				ft_atoi_abs(const char *nptr);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
char			*ft_itoa_base(int number, int base);
char			*ft_itoa_base_unsigned(unsigned int number, int base);
char			*ft_itoa_base_unsigned_long(size_t number, int base);
int				ft_core_zero(char *str, t_flags *flags, va_list *args);
int				ft_core_star(char *str, t_flags *flags, va_list *args);
int				ft_core_minus(char *str, t_flags *flags, va_list *args);
int				ft_core_digit(char *str, t_flags *flags, va_list *args);
int				ft_core_point(char *str, t_flags *flags, va_list *args);
int				ft_core_print(char *str, t_flags *flags, va_list *args);
int				ft_print_string(t_flags *flags, char *str);
int				ft_print_string_null(t_flags *flags);
int				ft_print_pointer(t_flags *flags, size_t ptr);
int				ft_print_pointer_null(t_flags *flags);
int				ft_print_decimal(t_flags *flags, int n);
int				ft_print_decimal_neg(t_flags *flags, char *num);
int				ft_print_decimal_unsigned(t_flags *flags, int num);
int				ft_print_exa(t_flags *flags, size_t n, int u);
int				ft_print_char(t_flags *flags, int c);
int				ft_print_zero(t_flags *flags);

#endif
