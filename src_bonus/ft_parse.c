/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:56:00 by adede             #+#    #+#             */
/*   Updated: 2026/02/20 05:29:45 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_flag(t_flags *flags, const char flag)
{
	if (flag == '-')
		flags->dash = true;
    else if (flag == '0')
		flags->zero = true;
    else if (flag == '.')
		flags->dot = true;
    else if (flag == '#')
		flags->hash = true;
    else if (flag == '+')
		flags->plus = true;
    else if (flag == ' ')
		flags->space = true;
}

int	ft_parse(const char *format, t_flags *flags)
{
	const char *start;

	start = format;
	format++;
	while (ft_strchr("-0.#+ ", *format))
    	ft_parse_flag(flags, *format++);
	return (format - start);
}