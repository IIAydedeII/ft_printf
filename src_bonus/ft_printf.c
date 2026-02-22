/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:50:06 by adede             #+#    #+#             */
/*   Updated: 2026/02/22 18:27:43 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdarg.h>

static int	ft_specifier(t_options *options, va_list arguments)
{
	char	specifier;
	int		length;

	specifier = options->specifier;
	length = 0;
	if (specifier == 'c')
		length = ft_print_char(va_arg(arguments, int), options);
	else if (specifier == 's')
		length = ft_print_str(va_arg(arguments, char *), options);
	else if (specifier == 'd' || specifier == 'i')
		length = ft_print_int(va_arg(arguments, int), options);
	else if (specifier == 'u')
		length = ft_print_uint(va_arg(arguments, unsigned int), options);
	else if (specifier == 'x' || specifier == 'X')
		length = ft_print_hex(va_arg(arguments, unsigned int), options);
	else if (specifier == 'p')
		length = ft_print_ptr((uintptr_t)va_arg(arguments, void *), options);
	else if (specifier == '%')
		length = ft_putchar('%', options);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list		arguments;
	t_options	*options;
	int			length;

	length = 0;
	options = ft_calloc(1, sizeof(t_options));
	if (!options)
		return (-1);
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format += ft_parse(format, options);
			length += ft_specifier(options, arguments);
		}
		else
			length += ft_putchar(*format++, options);
	};
	if (options->error)
		length = -1;
	return (va_end(arguments), free(options), length);
}
