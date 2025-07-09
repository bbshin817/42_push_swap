/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:28:30 by user              #+#    #+#             */
/*   Updated: 2025/05/18 03:39:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int		ra;
	int		b_max_value;
	int		b_min_value;
	int		size;

	b_max_value = get_max_value(stack_b);
	b_min_value = get_min_value(stack_b);
	node_a = stack_a->top;
	ra = 0;
	reset_command(stack_a);
	size = count_stack(stack_a);
	while (!node_a->is_null)
	{
		if (ra < size / 2)
			node_a->command.ra = ra;
		else
			node_a->command.rra = (size - ra);
		simulate_pos_a2b(stack_b, node_a, b_max_value, b_min_value);
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
	if (get_value_position(stack_a, a_min_value) <= count_stack(stack_a) / 2)
		while (a_min_value != stack_a->top->value)
			ra(stack_a);
	else
		while (a_min_value != stack_a->top->value)
			rra(stack_a);
}
