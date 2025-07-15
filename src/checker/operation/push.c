/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:13:33 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 17:07:35 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*first;
	t_node	*last;

	if (!src || !src->top || src->top->is_null)
		return ;
	first = src->top;
	first->prev->next = first->next;
	first->next->prev = first->prev;
	src->top = first->next;
	last = dest->top->prev;
	first->next = dest->top;
	first->prev = last;
	last->next = first;
	dest->top->prev = first;
	dest->top = first;
	return ;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	return ;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	return ;
}
