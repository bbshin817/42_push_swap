/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:27:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/13 01:23:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_stack(t_stack *stack)
{
	int		len;
	t_node	*node;

	len = 0;
	node = stack->top;
	while (node && !node->is_null)
	{
		node = node->next;
		len++;
	}
	return (len);
}

long	get_max_value(t_stack *stack)
{
	t_node	*node;
	long	value;

	node = stack->top;
	value = node->value;
	node = node->next;
	while (!node->is_null)
	{
		if (value < node->value)
			value = node->value;
		node = node->next;
	}
	return (value);
}

long	get_min_value(t_stack *stack)
{
	t_node	*node;
	long	value;

	node = stack->top;
	value = node->value;
	node = node->next;
	while (!node->is_null)
	{
		if (value > node->value)
			value = node->value;
		node = node->next;
	}
	return (value);
}
