/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:29:54 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/13 17:07:30 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int		choose_func(char format, va_list arg, t_format *view)
{
	int		count;

	count = 0;
	if (format == 's')
		count = print_str(view, va_arg(arg, char *));
	else if (format == 'c')
		count = print_char(view, va_arg(arg, int));
	else if (format == 'd' || format == 'i')
		count = print_signed_numb(view, va_arg(arg, int));
	else if (format == 'u')
		count = print_unsigned_numb(view, va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		count = print_hex(view, va_arg(arg, unsigned int));
	else if (format == 'p')
		count = print_hex(view, (unsigned long)va_arg(arg, void *));
	else if (format == '%')
		count = print_char(view, '%');
	else
		count = print_char(view, format);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	int			count;
	int			i;
	va_list		arg;
	t_format	*view;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			view = set_modificators(&i, format, arg);
			count += choose_func(format[i], arg, view);
			i++;
			free(view);
		}
		else
		{
			count++;
			ft_putchar_fd(format[i++], 1);
		}
	}
	va_end(arg);
	return (count);
}
