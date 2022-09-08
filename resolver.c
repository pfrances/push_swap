/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:37 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/08 15:52:32 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_index_limit(t_stack *stack)
{
	size_t	index_min;
	size_t	index_max;
	t_node	*trv;

	trv = stack->head;
	index_min = INT_MAX;
	index_max = 0;
	while (trv != NULL)
	{
		if (trv->index < index_min)
			index_min = trv->index;
		if (trv->index > index_max)
			index_max = trv->index;
		trv = trv->next;
	}
	return (index_max - ((index_max - index_min) / 2));
}

void	keep_half(t_stack *a, t_stack *b, t_output *output)
{
	size_t		nodes_to_push;
	size_t		count;
	t_limite	limite;

	if (b->total_nodes <= 5)
		return (sort_five_and_push(b, a, output));
	nodes_to_push = (b->total_nodes / 2) - (b->total_nodes % 2 == 0);
	limite.value = find_index_limit(b);
	limite.direction = UP;
	limite.zero_is_found = TRUE;
	count = 0;
	while (b->head != NULL && count < nodes_to_push)
	{
		find_nodes_easy_to_fixe(b, a, a->tail->index + 1, limite, output);
		if (b->head != NULL && b->head->index > limite.value)
		{
			push(b, a, output);
			count++;
		}
		else
			do_rotation(b, limite, output);
	}
	fixe_sorted_node(a, b, limite, output);
}

void	second_step(t_stack *a, t_stack *b, t_limite limite, t_output *output)
{
	reverse_rotate(b, output);
	push(b, a, output);
	while (b->tail->index == a->head->index - 1)
	{
		reverse_rotate(b, output);
		push(b, a, output);
	}
	while (a->head->index < limite.value)
		rotate(a, output);
	keep_half(a, b, output);
	while (a->head->index != 0)
	{
		if (a->head->next->index == a->tail->index + 1)
			swap(a, output);
		if (a->head->index == a->tail->index + 1)
			rotate(a, output);
		else
			push(a, b, output);
	}
	sort_five_and_push(b, a, output);
}

void	resolver(t_stack *a, t_stack *b, t_output *output)
{
	size_t		nodes_to_push;
	t_limite	limite;

	if (is_full_sorted(a))
		return ;
	if (a->total_nodes <= 5)
		up_to_five_nodes(a, b, output);
	else
	{
		nodes_to_push = (a->total_nodes / 2);
		limite.value = find_index_limit(a);
		limite.direction = DOWN;
		limite.zero_is_found = FALSE;
		while (b->total_nodes < nodes_to_push)
		{
			fixe_firsts_nodes(a, b, limite, output);
			if (a->head->index < limite.value)
				push(a, b, output);
			else
				do_rotation(a, limite, output);
		}
		second_step(a, b, limite, output);
	}
}
