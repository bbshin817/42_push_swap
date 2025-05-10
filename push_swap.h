/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/05/10 19:20:52 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				is_null;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void	print_error();
int		is_allow_characters(char *str);
int		is_duplicate(t_stack *stack);
int		append_value(char *values[], t_stack *stack);
void	print_node(t_node *node);
void	print_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	free_splits(char **splitted);
int		count_stack(t_stack *stack);
long	ft_atoi(const char *str);

#endif
