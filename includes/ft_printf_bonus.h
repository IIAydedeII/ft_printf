/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:34:11 by adede             #+#    #+#             */
/*   Updated: 2026/02/27 16:29:04 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <stdint.h> // to store pointer as an int (uintptr_t)
# include <stdbool.h> // to store flags as a bool

// ['-', '0', '.', '#', '+', ' ']
typedef struct s_flags
{
	bool	dash;
	bool	zero;
	bool	dot;
	bool	hash;
	bool	plus;
	bool	space;
}	t_flags;

// %[flags][width][.precision]specifier
typedef struct s_options
{
	t_flags	flags;
	int		width;
	int		precision;
	char	specifier;
	bool	error;
}	t_options;

int		ft_printf(const char *format, ...);

// Parse function

int		ft_parse(const char *format, t_options *options);

// Print functions

int		ft_print_char(char c, t_options *options);
int		ft_print_str(char *s, t_options *options);
int		ft_print_int(int i, t_options *options);
int		ft_print_uint(unsigned int i, t_options *options);
int		ft_print_hex(uintptr_t x, t_options *options);

// Print utilities

int		ft_padding(int length, t_options *options);
void	ft_padding_print(int length, t_options *options);
int		ft_precision(int length, t_options *options);
void	ft_precision_print(int length, t_options *options);

// Libft stand-in's

int		ft_putchar(char c, t_options *options);
int		ft_putstr(char *s, t_options *options);

#endif
