/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:21 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/11 18:52:21 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_a || argc == 1)
		print_error();
	if (!is_allow_argv(argv) || !append_value(argv, stack_a)
		|| is_duplicate(stack_a))
	{
		free_stacks(stack_a, stack_b);
		print_error();
	}
	sort(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
