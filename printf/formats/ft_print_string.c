/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:52:05 by sbaba             #+#    #+#             */
/*   Updated: 2025/04/01 17:13:29 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_string(char *arg)
{
	int	i;
	int	len;
	int	print_len;

	i = 0;
	len = 0;
	print_len = 0;
	if (!arg)
		return (ft_print_string("(null)"));
	while (arg[i] != '\0')
	{
		print_len = ft_print_char(arg[i]);
		if (print_len < 0)
			return (-1);
		len += print_len;
		i++;
	}
	return (len);
}
