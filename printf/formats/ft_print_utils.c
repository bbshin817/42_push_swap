/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:29:14 by sbaba             #+#    #+#             */
/*   Updated: 2025/04/01 17:29:07 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_hex(unsigned long n, int uppercase)
{
	int		len;
	int		print_len;
	char	*base;

	len = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		print_len = ft_putnbr_hex(n / 16, uppercase);
		if (print_len < 0)
			return (-1);
		len += print_len;
	}
	print_len = ft_print_char(base[n % 16]);
	if (print_len < 0)
		return (-1);
	len += print_len;
	return (len);
}
