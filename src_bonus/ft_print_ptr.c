/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 09:18:17 by adede            ###   ########.fr       */
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
	length = ft_uintptr_len(p) + 2;
	padding = options->width - length;
	if (padding < 0)
		padding = 0;
	if (!options->flags.dash)
		ft_padding(padding, options);
	ft_putstr("0x", options);
	ft_puthex(p, options);
	if (options->flags.dash)
		ft_padding(padding, options);
	if (options->width > length)
		return (options->width);
	return (length);
}
