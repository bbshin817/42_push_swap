/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/12 18:15:20 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	if (!stack)
		return ;
	node = stack->top;
	free(stack);
	if (!node)
		return ;
	while (node && !node->is_null)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	if (node)
		free(node);
	return ;
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}

void	free_splits(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return ;
}
