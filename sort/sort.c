/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:45:54 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/13 01:17:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3_values(t_stack *stack)
{
	long	max_value;

	max_value = get_max_value(stack);
	if (max_value == stack->top->value)
		ra(stack);
	else if (max_value == stack->top->next->value)
		rra(stack);
	if (stack->top->value > stack->top->next->value)
		sa(stack);
	return ;
}

void	sort_4_values(t_stack *stack_a, t_stack *stack_b)
{
	long	min_value;

	min_value = get_min_value(stack_a);
	while (stack_a->top->value != min_value)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3_values(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = count_stack(stack_a);
	if (is_sorted(stack_a) || stack_size < 2)
		return ;
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		sort_3_values(stack_a);
	else if (stack_size == 4)
		sort_4_values(stack_a, stack_b);
	else
		sort_over_5(stack_a, stack_b);
	return ;
}
