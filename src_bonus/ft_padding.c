/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:42:29 by adede             #+#    #+#             */
/*   Updated: 2026/02/25 16:53:49 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_padding_print(int padding, t_options *options)
{
	bool	numeric;

	numeric = ft_strchr("diuxX", options->specifier);
	while (padding--)
	{
		if (options->flags.zero && numeric && options->precision == 0)
			ft_putchar('0', options);
		else
			ft_putchar(' ', options);
	}
}

int	ft_padding(int length, t_options *options)
{
	int		padding;

	padding = options->width - length;
	if (padding < 0)
		padding = 0;
	return (padding);
}
