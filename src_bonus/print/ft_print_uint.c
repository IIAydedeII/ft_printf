/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/27 12:55:00 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_uint_len(unsigned int n)
{
	size_t	length;

	length = 1;
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static int	ft_putunbr_fd(unsigned int number, t_options *options)
{
	int	length;

	length = 0;
	if (number >= 10)
		length += ft_putunbr_fd(number / 10, options);
	return (length + ft_putchar((number % 10) + '0', options));
}

int	ft_print_uint(unsigned int i, t_options *options)
{
	int		length;
	int		precision;
	int		padding;

	length = ft_uint_len(i);
	if (options->flags.dot && i == 0)
		length = 0;
	precision = ft_precision(length, options);
	padding = ft_padding(length + precision, options);
	if (!options->flags.dash)
		ft_padding_print(padding, options);
	ft_precision_print(precision, options);
	if (length)
		ft_putunbr_fd(i, options);
	if (options->flags.dash)
		ft_padding_print(padding, options);
	return (length + precision + padding);
}
