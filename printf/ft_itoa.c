/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leweathe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:45:36 by leweathe          #+#    #+#             */
/*   Updated: 2020/05/01 10:31:22 by leweathe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*write_numb(char *str, int des, int numb)
{
	int		i;
	int		digit;

	i = 0;
	if (numb < 0)
		str[i++] = '-';
	while (des != 0)
	{
		digit = numb / des;
		if (digit < 0)
			digit = -digit;
		str[i++] = digit + 48;
		numb = numb % des;
		des /= 10;
	}
	str[i] = '\0';
	return (str);
}

static char		*write_unnumb(char *str, int des, unsigned int numb)
{
	int				i;
	unsigned int	digit;

	i = 0;
	while (des != 0)
	{
		digit = numb / des;
		str[i++] = digit + 48;
		numb = numb % des;
		des /= 10;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		des;
	int		numb;
	int		i;

	numb = n;
	des = 1;
	i = 1;
	if (n < 0)
		i++;
	while (numb /= 10)
	{
		des *= 10;
		i++;
	}
	numb = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str = write_numb(str, des, numb);
	return (str);
}

char			*ft_unitoa(unsigned int n)
{
	char			*str;
	int				des;
	unsigned int	numb;
	int				i;

	numb = n;
	des = 1;
	i = 1;
	while (numb /= 10)
	{
		des *= 10;
		i++;
	}
	numb = n;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str = write_unnumb(str, des, numb);
	return (str);
}
