/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/22 18:21:22 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	count += ft_print_char(hex_set[number % 16], options);
	return (count);
}

int	ft_print_hex(uintptr_t x, t_options *options)
{
	return (ft_puthex(x, options));
}
