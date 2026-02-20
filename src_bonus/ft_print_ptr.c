/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/19 19:44:25 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(uintptr_t p)
{
	int	length;
	int	written;

	length = 0;
	if (!p)
		return (ft_print_str("(nil)"));
	written = ft_print_str("0x");
	if (written == -1)
		return (-1);
	length += written;
	written = ft_print_hex(p, 'x');
	if (written == -1)
		return (-1);
	return (length + written);
}
