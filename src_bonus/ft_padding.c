/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:42:29 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 10:35:07 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_padding(int length, t_options *options)
{
	int		padding_zero;
	int		padding;
	bool	numeric;

	padding_zero = options->precision - length;
	if (padding_zero < 0)
		padding_zero = 0;
	padding = options->width - length - padding_zero;
	if (padding < 0)
		padding = 0;
	numeric = ft_strchr("diuxX", options->specifier);
	while (padding--)
	{
		if (options->flags.zero && numeric && options->precision == 0)
			ft_putchar('0', options);
		else
			ft_putchar(' ', options);
	}
	while (padding_zero-- && numeric)
		ft_putchar('0', options);
}
