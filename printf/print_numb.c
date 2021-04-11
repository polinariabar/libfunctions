/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:16:05 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/18 14:16:09 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_digits(int spaces, int zeros, t_format *view, char *str)
{
	if (view->flag == 'N' || (view->flag == '0' && view->dot == '.'))
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	if (str[0] == '-')
		ft_putchar_fd('-', 1);
	if (view->param == 'p')
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
	}
	while ((view->flag == '0' && view->dot != '.' ? spaces-- : zeros--) > 0)
		ft_putchar_fd('0', 1);
	if (!(str[0] == '0' && view->dot == '.' && view->accuracy == 0))
		ft_putstr_fd((str[0] == '-' ? str + 1 : str), 1);
	while (view->flag == '-' && spaces-- > 0)
		ft_putchar_fd(' ', 1);
}

int		print_signed_numb(t_format *view, int number)
{
	int		nb;
	int		count;
	int		spaces;
	int		zeros;
	char	*str;

	nb = number;
	count = 1;
	while (nb /= 10)
		count++;
	if (number < 0)
	{
		count++;
		view->accuracy++;
	}
	spaces = output_params(&zeros, count, view, number == 0 ? 0 : 1);
	str = ft_itoa(number);
	count = count_length(spaces, zeros, view, str);
	print_digits(spaces, zeros, view, str);
	free(str);
	return (count);
}

int		print_unsigned_numb(t_format *view, unsigned int number)
{
	unsigned int	nb;
	int				count;
	int				spaces;
	int				zeros;
	char			*str;

	nb = number;
	count = 1;
	while (nb /= 10)
		count++;
	spaces = output_params(&zeros, count, view, number == 0 ? 0 : 1);
	str = ft_unitoa(number);
	count = count_length(spaces, zeros, view, str);
	print_digits(spaces, zeros, view, str);
	free(str);
	return (count);
}

int		print_hex(t_format *view, unsigned long number)
{
	int				spaces;
	int				zeros;
	int				count;
	unsigned long	nb;
	char			*str;

	nb = number;
	count = 1;
	while (nb /= 16)
		count++;
	str = hex_to_str(count, number, view->param);
	spaces = output_params(&zeros, count, view, number == 0 ? 0 : 1);
	count = count_length(spaces, zeros, view, str);
	print_digits(spaces, zeros, view, str);
	free(str);
	return (count);
}
