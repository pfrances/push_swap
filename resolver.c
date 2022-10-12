/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:37 by pfrances          #+#    #+#             */
/*   Updated: 2022/10/08 16:43:30 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	break_into_three_part(t_tools *tools)
{
	set_index_limit(tools->a, tools, tools->a->total_nodes);
	while (has_nodes_under_limite(tools->a, tools))
	{
		if (tools->a->head->index <= tools->limite_high)
			push(tools->a, tools->b, tools->output);
		else
			rotate(tools->a, tools->output);
		if (tools->b->head != NULL
			&& tools->b->head->index <= tools->limite_low)
			rotate(tools->b, tools->output);
	}
}

void	resolver(t_tools *tools)
{
	if (is_full_sorted(tools->a) == true)
		return ;
	if (tools->total_nodes <= 5)
		return (up_to_five_nodes(tools->a, tools->b, tools->output));
	break_into_three_part(tools);
	while (tools->next_to_fix != tools->total_nodes)
	{
		stack_b_process(tools);
		stack_a_process(tools);
	}
}
