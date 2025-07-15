/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 17:21:08 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)argv;
	if (argc == 1)
		ft_error();
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		ft_error();
	stack_init(stack_a, stack_b);
	if (!append_value(argv, stack_a) || is_duplicate(stack_a)
		|| sort(stack_a, stack_b) == -1)
	{
		free_stacks(stack_a, stack_b);
		ft_error();
	}
	if (is_sorted(stack_a) && is_empty(stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stack_a, stack_b);
	return (0);
}
