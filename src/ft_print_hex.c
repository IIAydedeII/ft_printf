/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/10 14:59:04 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(uintptr_t number, char specifier)
{
	char	*hex_set;
	int		count;

	count = 0;
	if (specifier == 'x')
		hex_set = "0123456789abcdef";
	else
		hex_set = "0123456789ABCDEF";
	if (number >= 16)
		count += ft_puthex(number / 16, specifier);
	ft_putchar_fd(hex_set[number % 16], 1);
	count++;
	return (count);
}

int	ft_print_hex(uintptr_t x, char specifier)
{
	return (ft_puthex(x, specifier));
}
