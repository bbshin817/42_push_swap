/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/16 01:07:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(0);
	if (!is_allow_argv(argv))
		print_error();
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		print_error();
	stack_init(stack_a, stack_b);
	if (!append_value(argv, stack_a) || is_duplicate(stack_a))
	{
		free_stacks(stack_a, stack_b);
		print_error();
	}
	sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
