/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:10:56 by pfrances          #+#    #+#             */
/*   Updated: 2022/10/02 21:10:53 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restitute_to_a(t_stack *b, t_stack *a, t_tools *tools)
{
	if (tools->b->total_nodes <= 5)
		return (sort_five_and_push(tools->b, tools->a, tools));
	while (b->head != NULL && b->head->index >= tools->limite_low)
	{
		if (a->head->index < (tools->limite_low * 3) / 2
			&& a->head->index > tools->next_to_fix)
			rotate(a, tools->output);
		else
			push(b, a, tools->output);
	}
	while (tools->a->tail->index <= tools->limite_high
		&& tools->a->tail->index != tools->next_to_fix - 1)
		reverse_rotate(tools->a, tools->output);
}

void	stack_b_process(t_tools *tools)
{
	restitute_to_a(tools->b, tools->a, tools);
	if (tools->next_to_fix == tools->total_nodes)
		return ;
	set_index_limit(tools->b, tools, tools->b->total_nodes);
	while (has_nodes_over_limite(tools->b, tools))
	{
		if (tools->b->head->index >= tools->limite_low)
			push(tools->b, tools->a, tools->output);
		else
			rotate(tools->b, tools->output);
		if (tools->a->head->index <= tools->limite_high
			&& tools->a->head->index > tools->next_to_fix)
			rotate(tools->a, tools->output);
	}
	while (tools->a->tail->index <= tools->limite_high
		&& tools->a->tail->index != tools->next_to_fix - 1)
	{
		reverse_rotate(tools->a, tools->output);
		if (tools->b->tail->index >= (tools->limite_low * 3) / 2)
			reverse_rotate(tools->b, tools->output);
	}
	if (tools->b->total_nodes > 0)
		stack_b_process(tools);
}
