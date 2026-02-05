/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/05 17:28:13 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(int i)
{
	long	number;
	int		length;

	length = 0;
	number = i;
	ft_putnbr_fd(number, 1);
	if (number == 0)
		return (1);
	if (number < 0)
	{
		length++;
		number = -number;
	}
	while (number > 0)
	{
		length++;
		number /= 10;
	}
	return (length);
}
