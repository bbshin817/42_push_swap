/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:34:26 by sbaba             #+#    #+#             */
/*   Updated: 2025/04/01 17:25:17 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	branch_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, uintptr_t)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex_lower(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (ft_print_hex_upper(va_arg(args, unsigned int)));
	else if (specifier == '%')
		return (ft_print_percent());
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		strlen;
	int		print_len;

	count = 0;
	strlen = 0;
	print_len = 0;
	va_start(args, format);
	while (format[count] != '\0')
	{
		if (format[count] == '%')
		{
			count++;
			print_len = branch_specifier(format[count], args);
		}
		else
			print_len = ft_print_char(format[count]);
		if (print_len < 0)
			return (-1);
		strlen += print_len;
		count++;
	}
	va_end(args);
	return (strlen);
}
