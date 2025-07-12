/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/12 18:23:21 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top || stack->top->is_null)
		return (1);
	node = stack->top;
	while (!node->is_null)
	{
		if (node->next->is_null)
			break ;
		if ((long)node->value > (long)node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
