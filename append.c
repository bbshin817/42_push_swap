/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:27:16 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/08 19:22:00 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	append_value(char *values[], t_stack *stack)
{
	int		i;
	int		value;
	char	**strs;
	char	**tmp;

	i = 1;
	while (values[i])
	{
		strs = ft_split(values[i], ' ');
		if (!strs)
			return 0;
		tmp = strs;
		while (*strs)
		{
			value = ft_atoi(*strs);
			printf("%u, ", value);
			strs++;
		}
		free(tmp);
		i++;
	}
	exit(0);
	ft_printf("%s", stack);
	return 0;
}
