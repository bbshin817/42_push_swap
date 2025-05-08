/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:52:08 by sbaba             #+#    #+#             */
/*   Updated: 2025/04/01 17:29:40 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(unsigned int arg)
{
	int		len;
	char	*str;

	if (0 == arg)
		return (ft_print_char('0'));
	str = ft_utoa(arg);
	if (!str)
		return (-1);
	len = ft_print_string(str);
	free(str);
	if (len < 0)
		return (-1);
	return (len);
}
