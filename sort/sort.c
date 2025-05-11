/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:45:54 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/11 19:03:32 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2_values(t_stack *stack_a)
{
	sa(stack_a);
	print_stack(stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_size;

	stack_size = count_stack(stack_a);
	if (is_sorted(stack_a) || stack_size < 2)
		return ;
	if (stack_size == 2)
		sort_2_values(stack_a);
	count_stack(stack_b);
	return ;
}