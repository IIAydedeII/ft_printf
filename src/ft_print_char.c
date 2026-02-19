/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:33:09 by adede             #+#    #+#             */
/*   Updated: 2026/02/19 19:32:28 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_print_char(char c)
{
	return (ft_putchar(c));
}
