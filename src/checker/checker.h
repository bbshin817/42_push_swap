/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/15 17:20:47 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include "../../printf/ft_printf.h"
# include "../../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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

void		ft_error(void);
t_command	command_init(void);
t_node		*create_node(t_node *prev, int value, int is_null);
int			stack_init(t_stack *stack_a, t_stack *stack_b);
long		ex_atoi(const char *str);
void		free_stack(t_stack *stack);
void		free_stacks(t_stack *stack_a, t_stack *stack_b);
void		free_splits(char **splitted);
int			append_value(char *values[], t_stack *stack);
int			is_duplicate(t_stack *stack);
int			is_sorted(t_stack *stack);
int			is_empty(t_stack *stack);
void		print_stack(t_stack *stack);
int			count_stack(t_stack *stack);
int			sort(t_stack *a, t_stack *b);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

#endif