/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/05 16:11:07 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;

	if (stack->top == NULL)
		stack->top = new;
	else
	{
		last = stack->top;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

void	init(int argc, char *argv[], t_stack *stack)
{
	int	i;
	int	value;

	stack->top = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (!value)
			exit(1);
		create_node(stack, value);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;

	if (1 == argc)
		exit (0);
	init(argc, argv, &stack_a);
}
