/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/27 12:54:52 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_int_len(long n)
{
	size_t	length;

	length = 1;
	if (n < 0)
		n *= -1;
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
		number *= -1;
	if (number >= 10)
		length += ft_putnbr(number / 10, options);
	return (length + ft_putchar((number % 10) + '0', options));
}

static void	ft_sign(int i, t_options *options)
{
	if (i < 0)
		ft_putchar('-', options);
	else if (options->flags.plus)
		ft_putchar('+', options);
	else if (options->flags.space)
		ft_putchar(' ', options);
}

int	ft_print_int(int i, t_options *options)
{
	int		length;
	int		precision;
	bool	sign;
	int		padding;

	length = ft_int_len(i);
	if (options->flags.dot && i == 0)
		length = 0;
	precision = ft_precision(length, options);
	sign = (i < 0 || options->flags.plus || options->flags.space);
	padding = ft_padding(length + precision + sign, options);
	if (options->flags.zero && !options->flags.dot)
		ft_sign(i, options);
	if (!options->flags.dash)
		ft_padding_print(padding, options);
	if (!(options->flags.zero && !options->flags.dot))
		ft_sign(i, options);
	ft_precision_print(precision, options);
	if (length)
		ft_putnbr(i, options);
	if (options->flags.dash)
		ft_padding_print(padding, options);
	return (length + precision + sign + padding);
}
