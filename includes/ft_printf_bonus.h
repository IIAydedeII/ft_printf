/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:34:11 by adede             #+#    #+#             */
/*   Updated: 2026/02/20 05:41:05 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../Libft/libft.h"
# include <stdint.h> // to store pointer as an int (uintptr_t)
# include <stdbool.h> // to store flags as a bool

typedef struct s_flags
{
    bool	dash;
    bool	zero;
    bool	dot;
    bool	hash;
    bool	plus;
    bool	space;
}   t_flags;

// %[flags][width][.precision][specifier]
typedef struct s_options
{
	t_flags	flags;
    int		width;
}   t_options;

int	ft_printf(const char *format, ...);

// Parse functions
int	ft_parse(const char *format, t_options *options);

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
