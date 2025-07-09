/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/09 19:56:16 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include "../../printf/ft_printf.h"
# include "../../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	int	all;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}	t_command;

typedef struct s_node
{
	int				value;
	int				is_null;
	t_command		command;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void		ft_error(const char *message);
t_command	command_init(void);
t_node		*create_node(t_node *prev, int value, int is_null);
int			stack_init(t_stack *stack_a, t_stack *stack_b);
long		ex_atoi(const char *str);

#endif