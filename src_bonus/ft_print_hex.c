/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/25 09:56:14 by adede            ###   ########.fr       */
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
	int		padding;
	bool	hidden_zero;
	bool	prefixed;

	if (options->specifier == 'p' && x == 0)
		return (ft_putstr("(nil)", options));
	padding = 0;
	hidden_zero = (options->flags.dot && x == 0);
	prefixed = ((options->flags.hash && x != 0) || options->specifier == 'p');
	length = ft_uintptr_len(x, prefixed);
	length -= hidden_zero;
	if (!options->flags.dash)
		padding = ft_padding(length, options);
	if (!hidden_zero)
		ft_puthex(x, options, prefixed);
	if (options->flags.dash)
		padding = ft_padding(length, options);
	return (length + padding);
}
