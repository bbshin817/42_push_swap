/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:05:30 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/12 19:17:44 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sort_operate(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strncmp(operation, "sa", 2) == 0)
		sa(a);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		sb(b);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(operation, "rr", 2) == 0)
		rr(a, b);
	else if (ft_strncmp(operation, "rra", 2) == 0)
		rra(a);
	else if (ft_strncmp(operation, "rrb", 2) == 0)
		rrb(b);
	else if (ft_strncmp(operation, "rrr", 2) == 0)
		rrr(a, b);
	else
		return (-1);
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	char *line;

	(void)a;
	(void)b;
	line = get_next_line(0);
	while (line)
	{
		ft_printf("Operation: %s\n", line);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}