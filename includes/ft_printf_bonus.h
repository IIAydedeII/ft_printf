/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:34:11 by adede             #+#    #+#             */
/*   Updated: 2026/02/20 04:51:18 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../Libft/libft.h"
# include <stdint.h> // to store pointer as an int (uintptr_t)

int	ft_printf(const char *format, ...);

// Print functions
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(int i);
int	ft_print_uint(unsigned int i);
int	ft_print_hex(uintptr_t x, char specifier);
int	ft_print_ptr(uintptr_t p);

// Libft stand-in's
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
