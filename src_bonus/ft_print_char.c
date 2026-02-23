/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:33:09 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 09:50:26 by adede            ###   ########.fr       */
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

	length = 1;
	if (!options->flags.dash)
		ft_padding(length, options);
	ft_putchar(c, options);
	if (options->flags.dash)
		ft_padding(length, options);
	if (options->width > length)
		return (options->width);
	return (length);
}
