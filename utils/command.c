/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:54:57 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/13 01:23:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_command	command_init(void)
{
	t_command	command;

	command.all = 0;
	command.ra = 0;
	command.rra = 0;
	command.rb = 0;
	command.rrb = 0;
	command.rr = 0;
	command.rrr = 0;
	return (command);
}

void	reset_command(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (!node->is_null)
	{
		node->command = command_init();
		node = node->next;
	}
	return ;
}

int	get_commands_count(t_command command)
{
	int	i;

	i = 0;
	i += command.all;
	i += command.ra;
	i += command.rra;
	i += command.rb;
	i += command.rrb;
	i += command.rr;
	i += command.rrr;
	return (i);
}

void	do_command(t_command command, t_stack *stack_a, t_stack *stack_b)
{
	while (0 < command.ra && 0 < command.rb)
	{
		rr(stack_a, stack_b);
		command.ra--;
		command.rb--;
	}
	while (0 < command.rra && 0 < command.rrb)
	{
		command.rra--;
		command.rrb--;
		rrr(stack_a, stack_b);
	}
	while (0 < command.ra--)
		ra(stack_a);
	while (0 < command.rb--)
		rb(stack_b);
	while (0 < command.rra--)
		rra(stack_a);
	while (0 < command.rrb--)
		rrb(stack_b);
	return ;
}
