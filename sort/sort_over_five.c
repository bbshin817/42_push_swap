/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:28:30 by user              #+#    #+#             */
/*   Updated: 2025/05/12 02:53:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_cheapest_value(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->top;
	while (!node->is_null)
	{
		
		node = node->next;
	}
}

void	sort_over_5(t_stack *stack_a, t_stack *stack_b)
{
	long	b_min_value;
	long	b_max_value;
	long	closet_value;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (3 < count_stack(stack_a))
	{
		b_min_value = get_min_value(stack_b);
		b_max_value = get_max_value(stack_b);
		if (b_max_value < stack_a->top->value || stack_a->top->value < b_min_value)
		{
			pb(stack_a, stack_b);
			while (stack_b->top->value != b_max_value)
				rb(stack_a);
		}
		else
		{
		}
	}
}