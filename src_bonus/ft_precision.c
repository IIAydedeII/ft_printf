/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:42:29 by adede             #+#    #+#             */
/*   Updated: 2026/02/25 14:27:12 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_precision_print(int padding_zero, t_options *options)
{
	while (padding_zero--)
		ft_putchar('0', options);
}

int	ft_precision(int length, t_options *options)
{
	int		padding_zero;

	padding_zero = options->precision - length;
	if (padding_zero < 0)
		padding_zero = 0;
	return (padding_zero);
}
