/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:22:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/10/02 20:56:29 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_tools *tools, size_t nodes_to_push)
{
	size_t	count;

	count = 0;
	while (tools->a->head->index != 0 && count < nodes_to_push)
	{
		find_nodes_easy_to_fixe(tools->b, tools->a, tools);
		if (tools->a->head->next->index == tools->next_to_fix
			&& tools->a->head->index == tools->next_to_fix + 1)
			swap(tools->a, tools->output);
		if (tools->b->total_nodes >= 1
			&& tools->b->head->index == tools->next_to_fix)
			push(tools->b, tools->a, tools->output);
		if (tools->a->head->index == tools->next_to_fix)
		{
			count += rotate(tools->a, tools->output);
			tools->next_to_fix++;
		}
		else
			count += push(tools->a, tools->b, tools->output);
	}
}

size_t	restitute_index_limit(t_stack *stack, size_t nb_nodes)
{
	size_t	index_min;
	size_t	index_max;
	size_t	i;
	t_node	*trv;

	trv = stack->head;
	index_min = INT_MAX;
	index_max = 0;
	i = 0;
	while (trv != NULL && i < nb_nodes)
	{
		if (trv->index < index_min)
			index_min = trv->index;
		if (trv->index > index_max)
			index_max = trv->index;
		trv = trv->next;
		i++;
	}
	return (index_max - ((index_max - index_min) / 2));
}

void	push_to_b_and_rotate_a_to_back(t_tools *tools, size_t nodes_to_push)
{
	size_t	count;
	size_t	limite;

	count = 0;
	limite = restitute_index_limit(tools->a, nodes_to_push);
	while (count < nodes_to_push)
	{
		if (tools->next_to_fix != 0
			&& tools->a->tail->index == tools->next_to_fix - 1)
		{
			if (tools->a->head->index == tools->next_to_fix)
			{
				count += rotate(tools->a, tools->output);
				tools->next_to_fix++;
			}
		}
		if (tools->a->head->index != 0
			&& tools->a->head->index <= limite)
			count += push(tools->a, tools->b, tools->output);
		else if (tools->a->head->index != 0
			&& tools->a->head->index <= limite * 2)
			count += rotate(tools->a, tools->output);
	}
	while (tools->a->tail->index > tools->next_to_fix - 1)
		reverse_rotate(tools->a, tools->output);
}

void	stack_a_process(t_tools *tools)
{
	size_t	nodes_to_push;

	while (tools->a->head->index == tools->next_to_fix)
		tools->next_to_fix += rotate(tools->a, tools->output);
	nodes_to_push = calculate_nodes_to_push(tools);
	if (nodes_to_push < 20)
		push_all_to_b(tools, nodes_to_push);
	else
		push_to_b_and_rotate_a_to_back(tools, nodes_to_push);
	if (tools->b->total_nodes == 0
		&& tools->next_to_fix != tools->total_nodes)
		stack_a_process(tools);
}
