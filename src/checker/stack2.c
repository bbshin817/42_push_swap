/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 17:19:31 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_stack(t_stack *stack)
{
	int		len;
	t_node	*node;

	len = 0;
	node = stack->top;
	while (node && !node->is_null)
	{
		node = node->next;
		len++;
	}
	return (len);
}

int	is_empty(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node->is_null)
		return (1);
	return (0);
}
