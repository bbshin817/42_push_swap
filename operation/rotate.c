/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:13:33 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/11 18:59:01 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	reverse_rotate(t_stack *stack)
{
	t_node	*bottom;
	t_node	*null_node;

	if (!stack || !stack->top || count_stack(stack) < 2)
		return ;
	null_node = stack->top->prev;
	bottom = null_node->prev;
	bottom->prev->next = null_node;
	null_node->prev = bottom->prev;
	null_node->next = bottom;
	bottom->prev = null_node;
	bottom->next = stack->top;
	stack->top->prev = bottom;
	stack->top = bottom;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return ;
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return ;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return ;
}
