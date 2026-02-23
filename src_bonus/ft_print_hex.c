/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 22:55:44 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_uintptr_len(uintptr_t n)
{
	size_t	length;

	length = 1;
	while (n >= 16)
	{
		n /= 16;
		length++;
	}
	return (length);
}

int	ft_puthex(uintptr_t number, t_options *options)
{
	char	*hex_set;
	int		count;

	count = 0;
	if (options->specifier == 'x')
		hex_set = "0123456789abcdef";
	else
		hex_set = "0123456789ABCDEF";
	if (number >= 16)
		count += ft_puthex(number / 16, options);
	count += ft_putchar(hex_set[number % 16], options);
	return (count);
}

int	ft_print_hex(uintptr_t x, t_options *options)
{
	int		length;
	int		padding;
	bool	hidden_zero;

	padding = 0;
	length = ft_uintptr_len(x);
	hidden_zero = (options->flags.dot && x == 0);
	length -= hidden_zero;
	if (!options->flags.dash)
		padding = ft_padding(length, options);
	if (!hidden_zero)
		ft_puthex(x, options);
	if (options->flags.dash)
		padding = ft_padding(length, options);
	return (length + padding);
}
