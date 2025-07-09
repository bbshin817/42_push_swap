/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:48:45 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/20 17:54:31 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_node(t_node *node)
{
	if (!node)
		return ;
	ft_printf("{\n");
	ft_printf("    \x1b[36m\"pointer\"\x1b[39m : \x1b[33m%p\n", node);
	ft_printf("    \x1b[36m\"value\"\x1b[39m : \x1b[33m%d\n", node->value);
	ft_printf("    \x1b[36m\"prev\"\x1b[39m : \x1b[33m%p\n", node->prev);
	ft_printf("    \x1b[36m\"next\"\x1b[39m : \x1b[33m%p\n", node->next);
	ft_printf("    \x1b[36m\"is_null\"\x1b[39m : \x1b[33m%d\n", node->is_null);
	ft_printf("\x1b[39m}\n");
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
	{
		ft_printf("Stack is empty.");
		return ;
	}
	node = stack->top;
	while (node)
	{
		print_node(node);
		if (node->is_null)
			break ;
		node = node->next;
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
