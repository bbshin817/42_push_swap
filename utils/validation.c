/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:05:30 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/20 18:17:22 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check(char s, int *was_number, int *was_symbol)
{
	if (!*was_symbol && !*was_number && (s == '+' || s == '-'))
		*was_symbol = 1;
	else if ('0' <= s && s <= '9')
		*was_number = 1;
	else if (s == 32)
	{
		if (!*was_number)
			return (0);
		*was_symbol = 0;
		*was_number = 0;
	}
	else
		return (0);
	return (1);
}

int	is_allow_characters(char *str)
{
	int	i;
	int was_number;
	int	was_symbol;

	i = 0;
	was_number = 0;
	was_symbol = 0;
	while (str[i])
	{
		if (!check(str[i], &was_number, &was_symbol))
			return (0);
		i++;
	}
	if (!was_number)
		return (0);
	return (1);
}

int	is_allow_argv(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_allow_characters(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while (current && !current->is_null)
	{
		compare = current->next;
		while (compare && !compare->is_null)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top || stack->top->is_null)
		return (1);
	node = stack->top;
	while (!node->is_null)
	{
		if (node->next->is_null)
			break ;
		if ((long)node->value > (long)node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
