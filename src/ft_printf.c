/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:50:06 by adede             #+#    #+#             */
/*   Updated: 2026/02/05 13:05:37 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	length;

	length = 0;
	va_start(arguments, format);
	while (*format)
	{
		ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(arguments);
	return (length);
}
