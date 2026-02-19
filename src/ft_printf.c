/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:50:06 by adede             #+#    #+#             */
/*   Updated: 2026/02/19 19:32:28 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static int	ft_specifier(char specifier, va_list arguments)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length = ft_print_char(va_arg(arguments, int));
	else if (specifier == 's')
		length = ft_print_str(va_arg(arguments, char *));
	else if (specifier == 'd' || specifier == 'i')
		length = ft_print_int(va_arg(arguments, int));
	else if (specifier == 'u')
		length = ft_print_uint(va_arg(arguments, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		length = ft_print_hex(va_arg(arguments, unsigned int), specifier);
	else if (specifier == 'p')
		length = ft_print_ptr((uintptr_t)va_arg(arguments, void *));
	else if (specifier == '%')
		length = ft_print_char('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		length;
	int		written;

	length = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			written = ft_specifier(*format, arguments);
		}
		else
			written = ft_print_char(*format);
		if (written == -1)
			return (va_end(arguments), -1);
		length += written;
		format++;
	}
	va_end(arguments);
	return (length);
}
