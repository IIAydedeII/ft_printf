/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:34:11 by adede             #+#    #+#             */
/*   Updated: 2026/02/12 17:08:15 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "Libft/libft.h"
# include <stdarg.h> // for Variadic Functions
# include <stdint.h> // for storing pointer as an int (uintptr_t)

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(int i);
int	ft_print_uint(unsigned int i);
int	ft_print_hex(uintptr_t x, char specifier);
int	ft_print_ptr(uintptr_t p);

#endif
