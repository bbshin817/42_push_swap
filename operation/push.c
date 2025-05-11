/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:13:33 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/11 18:58:45 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*first;
	t_node	*last;

	if (!src || !src->top || src->top->is_null)
		return;
	first = src->top;
	first->next->prev = first->prev;
	first->prev->next = first->next;
	src->top = first->next;
	last = dest->top->prev;
	first->next = dest->top;
	dest->top->prev = first;
	first->prev = last;
	last->next = first;
	return ;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return ;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return ;
}
