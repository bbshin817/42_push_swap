/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/09 19:55:53 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	convert(const char *str, int flag)
{
	unsigned long	result;
	unsigned long	over;
	int				digit;

	result = 0;
	digit = 0;
	over = (unsigned long)LONG_MAX;
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		if (0 < result && flag == 1 && result > (over - digit) / 10)
			return (LONG_MAX);
		if (0 < result && flag == -1 && result > (over - digit + 1) / 10)
			return (LONG_MIN);
		result = result * 10 + digit;
		str++;
	}
	return (result);
}

long	ex_atoi(const char *str)
{
	int		flag;
	long	result;

	flag = 1;
	result = 0;
	while (((9 <= *str && *str <= 13) || *str == 32) && *str != '\0')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	result = convert(str, flag);
	return (result * flag);
}
