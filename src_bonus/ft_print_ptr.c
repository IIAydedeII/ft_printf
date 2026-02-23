/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 22:46:20 by adede            ###   ########.fr       */
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

int	ft_print_ptr(uintptr_t p, t_options *options)
{
	int	length;
	int	padding;

	if (!p)
		return (ft_putstr("(nil)", options));
	options->specifier = 'x';
	padding = 0;
	length = ft_uintptr_len(p) + 2;
	if (!options->flags.dash)
		padding = ft_padding(length, options);
	ft_putstr("0x", options);
	ft_puthex(p, options);
	if (options->flags.dash)
		padding = ft_padding(length, options);
	return (length + padding);
}
