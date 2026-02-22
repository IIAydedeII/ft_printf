/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/22 18:16:49 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_putunbr_fd(unsigned int number, t_options *options)
{
	int	length;

	length = 0;
	if (number >= 10)
		length += ft_putunbr_fd(number / 10, options);
	return (length + ft_print_char((number % 10) + '0', options));
}

int	ft_print_uint(unsigned int i, t_options *options)
{
	return (ft_putunbr_fd(i, options));
}
