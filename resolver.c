/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:37 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 02:20:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_half(t_tools *tools)
{
	if (tools->b->total_nodes <= 5)
		return (sort_five_and_push(tools->b, tools->a, tools));
	find_index_limit(tools->b, tools, tools->b->total_nodes);
	while (has_nodes_over_limite(tools->b, tools))
	{
		find_nodes_easy_to_fixe(tools->b, tools->a, tools);
		if (tools->b->head != NULL && tools->b->head->index >= tools->limite)
			push(tools->b, tools->a, tools->output);
		else
			do_rotation(tools->b, tools);
	}
	keep_half(tools);
}

void	resolver(t_tools *tools)
{
	if (tools->total_nodes <= 5)
		return (up_to_five_nodes(tools->a, tools->b, tools->output));
	find_index_limit(tools->a, tools, tools->a->total_nodes);
	tools->limite_direction = DOWN;
	while (has_nodes_under_limite(tools->a, tools))
	{
		find_nodes_easy_to_fixe(tools->a, tools->b, tools);
		if (tools->a->head->index <= tools->limite)
			push(tools->a, tools->b, tools->output);
		else
			do_rotation(tools->a, tools);
	}
	reverse_rotate(tools->b, tools->output);
	push(tools->b, tools->a, tools->output);
	while (tools->b->tail->index == tools->a->head->index - 1)
	{
		reverse_rotate(tools->b, tools->output);
		push(tools->b, tools->a, tools->output);
	}
	while (tools->a->head->index <= tools->limite)
		rotate(tools->a, tools->output);
	tools->limite_direction = UP;
	keep_half(tools);
}
