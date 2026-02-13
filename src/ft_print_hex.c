/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/13 12:39:46 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(uintptr_t number, char specifier)
{
	char	*hex_set;
	int		count;
	int		written;

	count = 0;
	if (specifier == 'x')
		hex_set = "0123456789abcdef";
	else
		hex_set = "0123456789ABCDEF";
	if (number >= 16)
		count += ft_puthex(number / 16, specifier);
	written = ft_putchar(hex_set[number % 16]);
	if (written == -1)
		return (-1);
	count += written;
	return (count);
}

int	ft_print_hex(uintptr_t x, char specifier)
{
	return (ft_puthex(x, specifier));
}
