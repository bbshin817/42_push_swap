/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:11:20 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/12 19:18:14 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || count_stack(stack) < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	first->prev = second;
	stack->top = second;
	return ;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return ;
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return ;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return ;
}
