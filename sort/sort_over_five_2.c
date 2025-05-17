/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 00:43:06 by user              #+#    #+#             */
/*   Updated: 2025/05/18 03:39:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_near_less_value(t_stack *stack, int value)
{
	t_node	*node;
	long	diff;
	int		v;
	long	current_diff;

	diff = LONG_MAX;
	v = 0;
	node = stack->top;
	while (!node->is_null)
	{
		current_diff = (long)value - (long)node->value;
		if (node->value < value && current_diff < diff)
		{
			diff = current_diff;
			v = node->value;
		}
		node = node->next;
	}
	if (diff == LONG_MAX)
		return (value);
	return (v);
}

int	get_near_over_value(t_stack *stack, int value)
{
	t_node	*node;
	int		v;
	long	diff;
	long	current_diff;

	diff = LONG_MAX;
	node = stack->top;
	while (!node->is_null)
	{
		current_diff = (long)node->value - (long)value;
		if (node->value > value && current_diff < diff)
		{
			diff = current_diff;
			v = node->value;
		}
		node = node->next;
	}
	if (diff == LONG_MAX)
		return (value);
	return (v);
}

void	simulate_pos_a2b(t_stack *stack_b, t_node *node, int max, int min)
{
	int	position;
	int	size;
	int	near;

	size = count_stack(stack_b);
	if (node->value > max || node->value < min)
	{
		position = get_value_position(stack_b, max);
		if (position < size / 2)
			node->command.rb += position;
		else
			node->command.rrb += (size - position);
	}
	else
	{
		near = get_near_less_value(stack_b, node->value);
		position = get_value_position(stack_b, near);
		if (position < size / 2)
			node->command.rb += position;
		else
			node->command.rrb += (size - position);
	}
	return ;
}

void	simulate_position_b2a(t_stack *stack_a, t_node *node, int max, int min)
{
	int	position;
	int	size;
	int	near;

	size = count_stack(stack_a);
	if (node->value > max || node->value < min)
	{
		position = get_value_position(stack_a, min);
		if (position < size / 2)
			node->command.ra += position;
		else
			node->command.rra += (size - position);
	}
	else
	{
		near = get_near_over_value(stack_a, node->value);
		position = get_value_position(stack_a, near);
		if (position < size / 2)
			node->command.ra += position;
		else
			node->command.rra += (size - position);
	}
	return ;
}

void	simulate_commands_count_back(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_b;
	int		rb;
	int		a_max_value;
	int		a_min_value;
	int		size;

	a_max_value = get_max_value(stack_a);
	a_min_value = get_min_value(stack_a);
	node_b = stack_b->top;
	rb = 0;
	reset_command(stack_b);
	size = count_stack(stack_b);
	while (!node_b->is_null)
	{
		if (rb < size / 2)
			node_b->command.rb = rb;
		else
			node_b->command.rrb = (size - rb);
		simulate_position_b2a(stack_a, node_b, a_max_value, a_min_value);
		rb++;
		node_b = node_b->next;
	}
	return ;
}
