/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 09:49:56 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_int_len(long n)
{
	size_t	length;

	length = 1;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static int	ft_putnbr(int n, t_options *options)
{
	int		length;
	long	number;

	length = 0;
	number = n;
	if (number < 0)
	{
		length += ft_putchar('-', options);
		number *= -1;
	}
	if (number >= 10)
		length += ft_putnbr(number / 10, options);
	return (length + ft_putchar((number % 10) + '0', options));
}

int	ft_print_int(int i, t_options *options)
{
	int	length;

	length = ft_int_len(i);
	if (!options->flags.dash)
		ft_padding(length, options);
	ft_putnbr(i, options);
	if (options->flags.dash)
		ft_padding(length, options);
	if (options->width > length)
		return (options->width);
	return (length);
}
