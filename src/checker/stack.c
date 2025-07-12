/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/12 18:14:51 by sbaba            ###   ########.fr       */
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

int	end_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*new_node;

	last = stack->top;
	while (last->next)
		last = last->next;
	new_node = create_node(last, 0, 1);
	if (!new_node)
		return (0);
	new_node->next = stack->top;
	last->next = new_node;
	stack->top->prev = new_node;
	return (1);
}

int	append_to_stack(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*new_node;

	if (!stack->top)
	{
		new_node = create_node(NULL, value, 0);
		if (!new_node)
			return (0);
		stack->top = new_node;
		return (1);
	}
	node = stack->top;
	while (node->next)
		node = node->next;
	new_node = create_node(node, value, 0);
	if (!new_node)
		return (0);
	node->next = new_node;
	return (1);
}

int	str2int(char *strs, t_stack *stack, char **tmp)
{
	long	value;

	value = ex_atoi(strs);
	if (INT_MAX < value || value < INT_MIN)
	{
		free_splits(tmp);
		return (0);
	}
	if (!append_to_stack(stack, value))
	{
		free_splits(tmp);
		return (0);
	}
	return (1);
}

int	append_value(char *values[], t_stack *stack)
{
	int		i;
	char	**strs;
	char	**tmp;

	i = 1;
	while (values[i])
	{
		strs = ft_split(values[i], ' ');
		if (!strs)
			return (0);
		tmp = strs;
		while (*strs)
		{
			if (!str2int(*strs, stack, tmp))
				return (0);
			strs++;
		}
		free_splits(tmp);
		i++;
	}
	end_stack(stack);
	return (1);
}
