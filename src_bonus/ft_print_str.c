/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:42:29 by adede             #+#    #+#             */
/*   Updated: 2026/02/23 22:37:21 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putstr(char *s, t_options *options)
{
	int	written;

	written = (int)write(1, s, ft_strlen(s));
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
	length = ft_strlen(s);
	if (!options->flags.dash)
		padding = ft_padding(length, options);
	ft_putstr(s, options);
	if (options->flags.dash)
		padding = ft_padding(length, options);
	return (length + padding);
}
