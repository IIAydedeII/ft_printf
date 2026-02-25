/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:42:29 by adede             #+#    #+#             */
/*   Updated: 2026/02/25 09:54:14 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_str_len(char *s, t_options *options)
{
	int	length;

	length = ft_strlen(s);
	if (options->flags.dot && \
		options->precision < length && \
		options->specifier == 's')
		length = options->precision;
	return (length);
}

int	ft_putstr(char *s, t_options *options)
{
	int	written;

	written = (int)write(1, s, ft_str_len(s, options));
	if (written < 0)
		options->error = true;
	return (written);
}

int	ft_print_str(char *s, t_options *options)
{
	int	length;
	int	padding;

	if (!s)
		return (ft_putstr("(null)", options));
	padding = 0;
	length = ft_str_len(s, options);
	if (!options->flags.dash)
		padding = ft_padding(length, options);
	ft_putstr(s, options);
	if (options->flags.dash)
		padding = ft_padding(length, options);
	return (length + padding);
}
