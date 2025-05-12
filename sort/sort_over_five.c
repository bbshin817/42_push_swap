/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:28:30 by user              #+#    #+#             */
/*   Updated: 2025/05/13 02:33:07 by user             ###   ########.fr       */
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

int	get_value_position(t_stack *stack, int value)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (!node->is_null)
	{
		if (node->value == value)
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}

void	simulate_commands_count(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	long	b_max_value;
	long	b_min_value;
	int		ra;
	int		near;

	b_max_value = get_max_value(stack_b);
	b_min_value = get_min_value(stack_b);
	node_a = stack_a->top;
	ra = 0;
	reset_command(stack_a);
	while (!node_a->is_null)
	{
		node_a->command.ra = ra;
		if (node_a->value > b_max_value || node_a->value < b_min_value)
			node_a->command.rb += get_value_position(stack_b, b_max_value);
		else
		{
			near = get_near_less_value(stack_b, node_a->value);
			node_a->command.rb += get_value_position(stack_b, near);
		}
		ra++;
		node_a = node_a->next;
	}
	return ;
}

void	do_min_command_value(t_stack *stack_a, t_stack *stack_b, int is_a)
{
	int			smallest;
	t_command	command;
	int			count;
	t_node		*node;

	smallest = INT_MAX;
	if (is_a)
		node = stack_a->top;
	else
		node = stack_b->top;
	while (!node->is_null)
	{
		count = get_commands_count(node->command);
		if (count < smallest)
		{
			command = node->command;
			smallest = count;
		}
		node = node->next;
	}
	do_command(command, stack_a, stack_b);
	return ;
}

void	sort_over_5(t_stack *stack_a, t_stack *stack_b)
{
	int	a_min_value;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (3 < count_stack(stack_a))
	{
		simulate_commands_count(stack_a, stack_b);
		do_min_command_value(stack_a, stack_b, 1);
		pb(stack_a, stack_b);
	}
	sort_3_values(stack_a);
	while (0 < count_stack(stack_b))
	{
		simulate_commands_count_back(stack_a, stack_b);
		do_min_command_value(stack_a, stack_b, 0);
		pa(stack_a, stack_b);
	}
	a_min_value = get_min_value(stack_a);
	while (a_min_value != stack_a->top->value)
		ra(stack_a);
}
