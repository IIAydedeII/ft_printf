/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/19 19:44:25 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(int n)
{
	int		length;
	int		written;
	long	number;

	length = 0;
	number = n;
	if (number < 0)
	{
		written = ft_putchar('-');
		if (written == -1)
			return (-1);
		length += written;
		number *= -1;
	}
	if (number >= 10)
	{
		written = ft_putnbr(number / 10);
		if (written == -1)
			return (-1);
		length += written;
	}
	written = ft_putchar((number % 10) + '0');
	if (written == -1)
		return (-1);
	return (length + written);
}

int	ft_print_int(int i)
{
	return (ft_putnbr(i));
}
