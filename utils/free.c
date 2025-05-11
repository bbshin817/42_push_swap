/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:20:00 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/12 01:25:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_stack(t_stack *stack)
{
	t_node *node;
	t_node *next_node;

	if (!stack || !stack->top)
		return;

	node = stack->top;
	while (!node->is_null)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	free(node);
	free(stack);
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

void free_splits(char **splitted)
{
	int i;

	i = 0;
	if (!splitted)
		return;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}