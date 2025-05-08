/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:52:03 by sbaba             #+#    #+#             */
/*   Updated: 2025/04/01 17:27:33 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_pointer(uintptr_t arg)
{
	int	len;
	int	print_len;

	len = 0;
	if (!arg)
		return (ft_print_string("(nil)"));
	print_len = ft_print_string("0x");
	if (print_len < 0)
		return (-1);
	len += print_len;
	print_len = ft_putnbr_hex(arg, 0);
	if (print_len < 0)
		return (-1);
	len += print_len;
	return (len);
}
