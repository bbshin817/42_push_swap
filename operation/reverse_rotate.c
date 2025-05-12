/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:23:09 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/12 16:24:04 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return ;
}