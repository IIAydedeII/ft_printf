/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/27 09:11:00 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_uintptr_len(uintptr_t n, bool prefixed)
{
	size_t	length;

	length = 1;
	if (prefixed)
		length += 2;
	while (n >= 16)
	{
		n /= 16;
		length++;
	}
	return (length);
}

int	ft_puthex(uintptr_t number, t_options *options, bool prefixed)
{
	char	*hex_set;
	int		count;

	count = 0;
	if (options->specifier == 'x' || options->specifier == 'p')
	{
		hex_set = "0123456789abcdef";
		if (prefixed)
			count += ft_putstr("0x", options);
	}
	else
	{
		hex_set = "0123456789ABCDEF";
		if (prefixed)
			count += ft_putstr("0X", options);
	}
	if (number >= 16)
		count += ft_puthex(number / 16, options, false);
	count += ft_putchar(hex_set[number % 16], options);
	return (count);
}

int	ft_print_hex(uintptr_t x, t_options *options)
{
	int		length;
	int		precision;
	int		padding;
	bool	hidden_zero;
	bool	prefixed;

	if (options->specifier == 'p' && x == 0)
		return (ft_putstr("(nil)", options));
	prefixed = ((options->flags.hash && x != 0) || options->specifier == 'p');
	length = ft_uintptr_len(x, prefixed);
	precision = ft_precision(length, options);
	padding = ft_padding(length + precision, options);
	hidden_zero = (options->flags.dot && options->precision == 0 && x == 0);
	length -= hidden_zero;
	if (!options->flags.dash)
		ft_padding_print(padding, options);
	ft_precision_print(precision, options);
	if (!hidden_zero)
		ft_puthex(x, options, prefixed);
	if (options->flags.dash)
		ft_padding_print(padding, options);
	return (length + precision + padding);
}
