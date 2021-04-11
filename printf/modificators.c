/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 10:54:51 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/18 10:54:58 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		view_mod(const char *format, int *i, t_format *view)
{
	view->flag = 'N';
	while (format[*i] == '-' || format[*i] == '0')
	{
		view->flag = (view->flag == '-' ? '-' : format[*i]);
		*i = *i + 1;
	}
}

void		width_mod(const char *format, int *i, va_list arg, t_format *view)
{
	view->width = 0;
	if (format[*i] == '*')
	{
		view->width = va_arg(arg, int);
		if (view->width < 0)
		{
			view->width = -1 * view->width;
			view->flag = '-';
		}
		*i = *i + 1;
	}
	else
		while ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '-')
		{
			if (format[*i] == '-')
			{
				view->width = 0;
				view->flag = '-';
			}
			else
				view->width = view->width * 10 + format[*i] - '0';
			*i = *i + 1;
		}
}

void		accur_mod(const char *format, int *i, va_list arg, t_format *view)
{
	int		sign;

	sign = 1;
	view->accuracy = 0;
	if (format[*i] == '*')
	{
		view->accuracy = va_arg(arg, int);
		*i = *i + 1;
	}
	while ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '-')
	{
		if (format[*i] == '-')
		{
			view->accuracy = 0;
			sign = -1;
		}
		else
			view->accuracy = view->accuracy * 10 + format[*i] - '0';
		*i = *i + 1;
	}
	if (sign < 0 || view->accuracy < 0)
	{
		view->dot = 0;
		view->accuracy = 0;
	}
}

t_format	*set_modificators(int *i, const char *format, va_list arg)
{
	t_format	*view;

	view = malloc(sizeof(t_format));
	view->flag = 'N';
	view->width = 0;
	view->dot = 0;
	view->accuracy = 0;
	*i = *i + 1;
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '.' ||
		format[*i] == '-' || format[*i] == '*')
	{
		view_mod(format, i, view);
		width_mod(format, i, arg, view);
		if (format[*i] == '.')
		{
			*i = *i + 1;
			view->dot = '.';
			accur_mod(format, i, arg, view);
		}
	}
	while (format[*i] == '.')
		*i = *i + 1;
	view->param = format[*i];
	return (view);
}
