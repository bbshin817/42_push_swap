/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:27:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/10 17:30:23 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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