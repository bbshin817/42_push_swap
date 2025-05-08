/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:51:48 by sbaba             #+#    #+#             */
/*   Updated: 2025/04/01 16:57:09 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(int arg)
{
	int		len;
	char	*str;

	str = ft_itoa(arg);
	if (!str)
		return (-1);
	len = ft_print_string(str);
	free(str);
	return (len);
}
