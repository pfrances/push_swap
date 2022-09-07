/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:37 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/07 03:27:20 by pfrances         ###   ########.fr       */
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

void	keep_half(t_stack *a, t_stack *b)
{
	size_t	nodes_to_push;
	size_t	index_limit;
	size_t	count;

	if (b->total_nodes <= 5)
		return (sort_five_and_push(b, a));
	nodes_to_push = (b->total_nodes / 2) - (b->total_nodes % 2 == 0);
	index_limit = find_index_limit(b);
	count = 0;
	while (count < nodes_to_push)
	{
		if (a->tail->index < index_limit)
			find_nodes_easy_to_fixe(b, a, a->tail->index + 1);
		if (b->head->index > index_limit)
		{
			push(b, a);
			count++;
		}
		else
			do_rotation(b, index_limit, UPPER);
	}
	fixe_sorted_node(a, b, index_limit);
}

void	second_step(t_stack *a, t_stack *b, size_t index_limit)
{
	reverse_rotate(b);
	push(b, a);
	while (b->tail->index == a->head->index - 1)
	{
		reverse_rotate(b);
		push(b, a);
	}
	while (a->head->index < index_limit)
		rotate(a);
	keep_half(a, b);
	while (a->head->index != 0)
	{
		if (a->head->next->index == a->tail->index + 1)
			swap(a);
		if (a->head->index == a->tail->index + 1)
			rotate(a);
		else
			push(a, b);
	}
	sort_five_and_push(b, a);
}

void	resolver(t_stack *a, t_stack *b)
{
	size_t	nodes_to_push;
	size_t	index_limit;
	t_bool	zero_found;

	if (is_full_sorted(a))
		return ;
	if (a->total_nodes <= 5)
		up_to_five_nodes(a, b);
	else
	{
		nodes_to_push = (a->total_nodes / 2);
		index_limit = find_index_limit(a);
		zero_found = FALSE;
		while (b->total_nodes < nodes_to_push)
		{
			if (fixe_firsts_nodes(a, b, &zero_found, index_limit) == TRUE)
				;
			else if (a->head->index < index_limit)
				push(a, b);
			else
				do_rotation(a, index_limit, LOWER);
		}
		// print_lists(a, b);
		// return ;
		second_step(a, b, index_limit);
	}
}
