/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:23:57 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/18 14:23:59 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		count_length(int spaces, int zeros, t_format *view, char *str)
{
	int count;

	count = 0;
	if (view->flag == 'N' || (view->flag == '0' && view->dot == '.'))
		while (spaces-- > 0)
			count++;
	if (view->param == 'p')
		count += 2;
	while ((view->flag == '0' && view->dot != '.' ? spaces-- : zeros--) > 0)
		count++;
	if (!(str[0] == '0' && view->dot == '.' && view->accuracy == 0))
		count = count + (int)ft_strlen(str);
	while (view->flag == '-' && spaces-- > 0)
		count++;
	return (count);
}

int		output_params(int *zeros, int count, t_format *view, int number)
{
	int		spaces;

	count = (view->param == 'p' ? count + 2 : count);
	spaces = view->accuracy > count ? view->width - view->accuracy :
			view->width - count;
	if (spaces > 0 && number == 0 && view->dot == '.' && view->accuracy == 0)
		spaces = spaces + 1;
	*zeros = view->accuracy > count ? view->accuracy - count : 0;
	return (spaces);
}

char	*hex_to_str(int count, unsigned long number, char param)
{
	char	*str;
	int		digit;
	char	tochar;

	str = (char *)malloc(sizeof(char) * count + 1);
	str[count--] = '\0';
	tochar = (param == 'X' ? 'A' - 10 : 'a' - 10);
	while (number / 16)
	{
		digit = number % 16;
		str[count--] = digit + (digit < 10 ? '0' : tochar);
		number = number / 16;
	}
	str[count--] = number + (number < 10 ? '0' : tochar);
	return (str);
}
