/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:22:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/11 01:02:17 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_tools *tools, size_t nodes_to_push)
{
	size_t	count;

	count = 0;
	while (tools->a->head->index != 0 && count < nodes_to_push)
	{
		if (tools->a->head->next->index == tools->next_to_fix
			&& tools->a->head->index == tools->next_to_fix + 1)
			swap(tools->a, tools->output);
		if (tools->b->total_nodes >= 1
			&& tools->b->head->index == tools->next_to_fix)
			push(tools->b, tools->a, tools->output);
		else if (tools->a->head->index == tools->next_to_fix)
		{
			rotate(tools->a, tools->output);
			tools->next_to_fix++;
			count++;
		}
		else
		{
			push(tools->a, tools->b, tools->output);
			count++;
		}
	}
}

void	push_to_b_and_rotate_a_to_back(t_tools *tools, size_t nodes_to_push)
{
	size_t	count;

	count = 0;
	find_index_limit(tools->a, tools, nodes_to_push);
	while (count < nodes_to_push)
	{
		if (tools->a->head->index != 0
			&& tools->a->head->index < tools->limite)
			push(tools->a, tools->b, tools->output);
		else
			do_rotation(tools->a, tools);
		count++;
	}
	while (tools->a->tail->index != tools->next_to_fix - 1)
		reverse_rotate(tools->a, tools->output);
}

void	a_stack_process(t_tools *tools)
{
	size_t	nodes_to_push;

	nodes_to_push = calculate_nodes_to_push(tools);
	if (nodes_to_push < 16)
		push_all_to_b(tools, nodes_to_push);
	else
		push_to_b_and_rotate_a_to_back(tools, nodes_to_push);
	if (tools->next_to_fix != tools->total_nodes)
		keep_half(tools);
}

int	found_closest_nodes(t_stack *src, size_t next_to_fix)
{
	int		moves_from_head;
	int		moves_from_tail;
	t_node	*trv;

	trv = src->head;
	moves_from_head = 0;
	while (trv != NULL && trv->index != next_to_fix)
	{
		moves_from_head++;
		trv = trv->next;
	}
	if (trv == NULL)
		return (INT_MAX);
	trv = src->head;
	moves_from_tail = 1;
	while (trv != NULL)
	{
		moves_from_tail++;
		if (trv->index == next_to_fix)
			moves_from_tail = 1;
		trv = trv->next;
	}
	if (moves_from_head < moves_from_tail)
		return (moves_from_head);
	return (-moves_from_tail);
}

t_bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, t_tools *tools)
{
	int	nbr_of_moves;

	if (src->head == NULL)
		return (FALSE);
	nbr_of_moves = found_closest_nodes(src, tools->next_to_fix);
	if (ft_abs(nbr_of_moves) <= 5)
	{
		if (nbr_of_moves >= 0)
			while (nbr_of_moves--
				&& !is_node_to_push(tools, src->head->index))
				rotate(src, tools->output);
		else
			while (nbr_of_moves++
				&& !is_node_to_push(tools, src->head->index))
				reverse_rotate(src, tools->output);
		if (src->head->index == tools->next_to_fix)
		{
			push(src, dst, tools->output);
			rotate(dst, tools->output);
			tools->next_to_fix++;
			return (TRUE);
		}
	}
	return (FALSE);
}
