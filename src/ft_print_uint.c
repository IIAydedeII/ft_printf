/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:17:56 by adede             #+#    #+#             */
/*   Updated: 2026/02/05 19:10:51 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_uintlen(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

static void	ft_putunbr_fd(unsigned int number, int fd)
{
	if (number >= 10)
		ft_putunbr_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
}

int	ft_print_uint(unsigned int i)
{
	ft_putunbr_fd(i, 1);
	return (ft_uintlen(i));
}
