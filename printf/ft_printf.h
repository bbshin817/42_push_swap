/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:34:30 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/08 17:26:27 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <inttypes.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_hex_lower(unsigned int arg);
int	ft_print_hex_upper(unsigned int arg);
int	ft_print_int(int arg);
int	ft_print_percent(void);
int	ft_print_pointer(uintptr_t arg);
int	ft_print_string(char *arg);
int	ft_print_unsigned(unsigned int arg);
int	ft_putnbr_hex(unsigned long n, int uppercase);

#endif