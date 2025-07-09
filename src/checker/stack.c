/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/09 19:52:12 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	stack_init(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*new_node;

	stack_a->top = NULL;
	stack_b->top = NULL;
	new_node = create_node(NULL, 0, 1);
	if (!new_node)
		return (0);
	new_node->prev = new_node;
	new_node->next = new_node;
	stack_b->top = new_node;
	return (1);
}

int	append_values(char *values[], t_stack *stack)
{
	int		i;
	char 	**splitted;
	char	**tmp;

	i = 0;
	while (values[i])
	{
		splitted = ft_split(values[i], ' ');
		if (!splitted)
			return (-1);
		tmp = splitted;
		while (*splitted)
		{
			splitted++;
		}
		i++;
	}
	return (0);
}