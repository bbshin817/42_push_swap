/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaba <sbaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:35:29 by sbaba             #+#    #+#             */
/*   Updated: 2025/07/09 19:42:54 by sbaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_command	command_init(void)
{
	t_command	command;

	command.all = 0;
	command.ra = 0;
	command.rra = 0;
	command.rb = 0;
	command.rrb = 0;
	command.rr = 0;
	command.rrr = 0;
	return (command);
}