/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:20:00 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/10 19:23:20 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
		if (node->is_null)
		{
			free(node);
			break;
		}
	}

	free(stack);
}

void	free_splits(char **splitted)
{
	int i;
	
	i = 0;
	if (!splitted)
		return;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}