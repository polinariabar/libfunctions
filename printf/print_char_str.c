/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:19:46 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/18 14:19:49 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_str(t_format *view, char *str)
{
	int		i;
	int		count;

	i = 0;
	if (!(str))
		str = "(null)";
	if (view->dot == '.')
		view->accuracy = ((int)ft_strlen(str) <
		view->accuracy ? (int)ft_strlen(str) : view->accuracy);
	else
		view->accuracy = ft_strlen(str);
	while (view->flag == '-' && i < view->accuracy)
		ft_putchar_fd(str[i++], 1);
	count = i;
	while (view->accuracy < view->width--)
	{
		count++;
		ft_putchar_fd(view->flag == '0' ? '0' : ' ', 1);
	}
	while (view->flag != '-' && view->accuracy--)
	{
		count++;
		ft_putchar_fd(*str++, 1);
	}
	return (count);
}

int		print_char(t_format *view, char symbol)
{
	int		width;

	width = view->width;
	if (view->flag == '-')
		ft_putchar_fd(symbol, 1);
	while (view->width-- > 1)
		ft_putchar_fd((view->flag == '0' ? '0' : ' '), 1);
	if (view->flag != '-')
		ft_putchar_fd(symbol, 1);
	return (width > 1 ? width : 1);
}
