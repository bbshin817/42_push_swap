/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:05:30 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 17:19:50 by sbaba            ###   ########.fr       */
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
	else if (ft_strncmp(operation, "rra", 3) == 0)
		rra(a);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		rrb(b);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		rrr(a, b);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		ra(a);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rb(b);
	else if (ft_strncmp(operation, "rr", 2) == 0)
		rr(a, b);
	else
		return (-1);
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	int		result;
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		result = sort_operate(line, a, b);
		free(line);
		if (result == -1)
		{
			get_next_line(-1);
			return (-1);
		}
		line = get_next_line(0);
	}
	free(line);
	return (0);
}
