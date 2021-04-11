/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polinariabar <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:35:46 by polinaria         #+#    #+#             */
/*   Updated: 2020/05/13 16:35:57 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_format
{
	char		flag;
	int			width;
	char		dot;
	int			accuracy;
	char		param;
}				t_format;

int				ft_printf(const char *format, ...);
int				print_str(t_format *view, char *str);
int				print_char(t_format *view, char symbol);
int				print_unsigned_numb(t_format *view, unsigned int number);
int				print_signed_numb(t_format *view, int number);
int				print_hex(t_format *view, unsigned long number);
int				count_length(int spaces, int zeros, t_format *view, char *str);
int				choose_func(char format, va_list arg, t_format *view);
int				output_params(int *zeros, int count, t_format *view,
						int number);
size_t			ft_strlen(const char *str);
char			*hex_to_str(int count, unsigned long number, char param);
char			*ft_itoa(int n);
char			*ft_unitoa(unsigned int n);
void			print_digits(int spaces, int zeros, t_format *view, char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			view_mod(const char *format, int *i, t_format *view);
void			width_mod(const char *format, int *i, va_list arg,
						t_format *view);
void			accur_mod(const char *format, int *i, va_list arg,
						t_format *view);
t_format		*set_modificators(int *i, const char *format, va_list arg);

#endif
