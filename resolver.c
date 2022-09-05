/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:37 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 01:29:44 by pfrances         ###   ########.fr       */
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

void	fixe_sorted_node(t_stack *a, t_stack *b, size_t index_limit)
{
	size_t	count;
	size_t	nodes_to_push;

	keep_half(a, b);
	count = 0;
	nodes_to_push = (index_limit - a->tail->index) - 1;
	while (a->head->index > 0 && count < nodes_to_push)
	{
		if (a->head->index == a->tail->index + 1)
			rotate(a);
		else
			push(a, b);
		count++;
	}
	keep_half(a, b);
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
		if (b->head->index > index_limit)
		{
			if (a->head->index == a->tail->index + 1)
				rotate(a);
			else
				push(b, a);
			count++;
		}
		else
			rotate(b);
	}
	fixe_sorted_node(a, b, index_limit);
}

void	second_step(t_stack *a, t_stack *b)
{
	keep_half(a, b);
	while (a->head->index != 0)
	{
		if (a->head->index == a->tail->index + 1)
			rotate(a);
		else
			push(a, b);
	}
	up_to_five_nodes(b, a);
	while (b->head != NULL)
	{
		push(b, a);
		rotate(a);
	}
}

void	resolver(t_stack *a, t_stack *b)
{
	size_t	nodes_to_push;
	size_t	index_limit;

	if (is_full_sorted(a))
		return ;
	if (a->total_nodes <= 5)
		up_to_five_nodes(a, b);
	else
	{
		nodes_to_push = (a->total_nodes / 2);
		index_limit = find_index_limit(a);
		while (b->total_nodes < nodes_to_push)
		{
			if (a->head->index < index_limit)
				push(a, b);
			else
				rotate(a);
		}
		second_step(a, b);
	}
}
