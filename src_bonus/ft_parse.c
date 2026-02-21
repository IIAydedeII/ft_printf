/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:56:00 by adede             #+#    #+#             */
/*   Updated: 2026/02/21 03:02:10 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_flag(t_options *options, const char flag)
{
	if (flag == '-')
		options->flags.dash = true;
    else if (flag == '0')
		options->flags.zero = true;
    else if (flag == '#')
		options->flags.hash = true;
    else if (flag == '+')
		options->flags.plus = true;
    else if (flag == ' ')
		options->flags.space = true;
}

int	ft_parse(const char *format, t_options *options)
{
	const char	flags[] = "-0#+ ";
	const char	*start;

	start = format;
	format++;
	while (ft_strchr(flags, *format))
    	ft_parse_flag(options, *format++);
	if (ft_isdigit(*format))
	{
    	options->width = ft_atoi(format);
        while (ft_isdigit(*format))
            format++;
	}
	if (*format == '.')
	{
		format++;
		options->precision = ft_atoi(format);
        while (ft_isdigit(*format))
            format++;
	}
	return (format - start);
}