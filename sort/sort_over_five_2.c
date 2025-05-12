/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 00:43:06 by user              #+#    #+#             */
/*   Updated: 2025/05/13 01:19:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_near_over_value(t_stack *stack, int value)
{
	t_node	*node;
	int		v;
	int		diff;

	diff = INT_MAX;
	node = stack->top;
	while (!node->is_null)
	{
		if (node->value > value && node->value - value < diff)
		{
			diff = node->value - value;
			v = node->value;
		}
		node = node->next;
	}
	if (diff == INT_MAX)
		return (value);
	return (v);
}

void	simulate_commands_count_back(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;
	long	a_max_value;
	long	a_min_value;
	int		rb;
	int		near;

	a_max_value = get_max_value(stack_a);
	a_min_value = get_min_value(stack_a);
	node_b = stack_b->top;
	rb = 0;
	reset_command(stack_b);
	while (!node_b->is_null)
	{
		node_b->command.rb = rb;
		if (node_b->value > a_max_value || node_b->value < a_min_value)
			node_b->command.ra = get_value_position(stack_a, a_min_value);
		else
		{
			near = get_near_over_value(stack_a, node_b->value);
			node_b->command.ra += get_value_position(stack_a, near);
		}
		rb++;
		node_b = node_b->next;
	}
	return ;
}
