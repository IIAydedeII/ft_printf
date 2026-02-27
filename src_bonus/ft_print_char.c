/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:33:09 by adede             #+#    #+#             */
/*   Updated: 2026/02/27 09:14:01 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c, t_options *options)
{
	int	written;

	written = (int)write(1, &c, 1);
	if (written < 0)
		options->error = true;
	return (written);
}

int	ft_print_char(char c, t_options *options)
{
	int	length;
	int	padding;

	length = 1;
	padding = ft_padding(length, options);
	if (!options->flags.dash)
		ft_padding_print(padding, options);
	ft_putchar(c, options);
	if (options->flags.dash)
		ft_padding_print(padding, options);
	return (length + padding);
}
