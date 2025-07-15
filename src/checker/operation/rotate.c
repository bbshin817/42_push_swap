/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:13:33 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 17:07:52 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate(t_stack *stack)
{
	t_node	*top;
	t_node	*null_node;

	if (!stack || !stack->top || count_stack(stack) < 2)
		return ;
	top = stack->top;
	null_node = top->prev;
	top->next->prev = null_node;
	null_node->next = top->next;
	stack->top = top->next;
	null_node->prev->next = top;
	top->prev = null_node->prev;
	top->next = null_node;
	null_node->prev = top;
	return ;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	return ;
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	return ;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	return ;
}
