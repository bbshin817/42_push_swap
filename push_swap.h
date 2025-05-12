/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/13 02:38:57 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>

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

void		print_error(void);
int			is_allow_characters(char *str);
int			is_allow_argv(char *argv[]);
int			is_duplicate(t_stack *stack);
int			is_sorted(t_stack *stack);
int			append_value(char *values[], t_stack *stack);
t_command	command_init(void);
t_node		*create_node(t_node *prev, int value, int is_null);
void		print_node(t_node *node);
void		print_stack(t_stack *stack);
void		free_stack(t_stack *stack);
void		free_stacks(t_stack *stack_a, t_stack *stack_b);
void		free_splits(char **splitted);
int			count_stack(t_stack *stack);
int			get_max_value(t_stack *stack);
int			get_min_value(t_stack *stack);
long		ex_atoi(const char *str);
void		reset_command(t_stack *stack);
int			get_commands_count(t_command command);
void		do_command(t_command command, t_stack *stack_a, t_stack *stack_b);
int			get_value_position(t_stack *stack, int value);
void		simulate_commands_count_back(t_stack *stack_a, t_stack *stack_b);
void		sort_3_values(t_stack *stack);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		sort(t_stack *stack_a, t_stack *stack_b);
void		sort_over_5(t_stack *stack_a, t_stack *stack_b);

#endif
