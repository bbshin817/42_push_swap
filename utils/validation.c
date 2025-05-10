/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:05:30 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/10 19:20:13 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_allow_characters(char *str)
{
	int	i;
	int	was_number;

	i = 0;
	was_number = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			was_number = 1;
		else if (str[i] == '+' || str[i] == '-')
			was_number = 0;
		else if (str[i] == 32)
		{
			if (!was_number)
				return (0);
		}
		else
			return (0);
		i++;
	}
	if (!was_number)
		return (0);
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while (current && !current->is_null)
	{
		compare = current->next;
		while (compare && !compare->is_null)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}