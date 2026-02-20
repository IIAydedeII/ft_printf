/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/19 19:44:25 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunbr_fd(unsigned int number)
{
	int	length;
	int	written;

	length = 0;
	if (number >= 10)
	{
		written = ft_putunbr_fd(number / 10);
		if (written == -1)
			return (-1);
		length += written;
	}
	written = ft_putchar((number % 10) + '0');
	if (written == -1)
		return (-1);
	return (length + written);
}

int	ft_print_uint(unsigned int i)
{
	return (ft_putunbr_fd(i));
}
