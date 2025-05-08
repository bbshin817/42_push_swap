/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:05:30 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/08 19:07:41 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	echo_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	is_allow_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9')
				|| str[i] == '+' || str[i] == '-' || str[i] == 32))
			return (0);
		i++;
	}
	return (1);
}
