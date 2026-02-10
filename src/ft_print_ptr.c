/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:23:46 by adede             #+#    #+#             */
/*   Updated: 2026/02/10 14:58:48 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(uintptr_t p)
{
	if (!p)
		return (ft_print_str("(nil)"));
	return (ft_print_str("0x") + ft_print_hex(p, 'x'));
}	
