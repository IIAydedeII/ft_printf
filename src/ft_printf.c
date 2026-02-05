/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:50:06 by adede             #+#    #+#             */
/*   Updated: 2026/02/05 18:44:15 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		length;

	length = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			length += ft_specifier(*format, arguments);
		}
		else
			length += ft_print_char(*format);
		format++;
	}
	va_end(arguments);
	return (length);
}
