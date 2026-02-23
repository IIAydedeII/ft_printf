/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:42:29 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 09:49:04 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_padding(int length, t_options *options)
{
	int	padding;

	padding = options->width - length;
	if (padding < 0)
		padding = 0;
	while (padding--)
	{
		if (options->flags.zero && ft_strchr("diuoxX", options->specifier))
			ft_putchar('0', options);
		else
			ft_putchar(' ', options);
	}
}
