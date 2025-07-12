/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/12 18:24:25 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int argc, char *argv[])
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
	if (!append_value(argv, stack_a) || is_duplicate(stack_a))
	{
		free_stacks(stack_a, stack_b);
		ft_error();
	}
	return (0);
}