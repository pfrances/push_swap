/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_fixing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:22:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 03:03:28 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fixe_sorted_node(t_tools *tools)
{
	size_t	nodes_to_push;
	size_t	count;

	nodes_to_push = calculate_nodes_to_push(tools);
	count = 0;

	if (nodes_to_push < 16)
	{
		while (tools->a->head->index != 0 && count < nodes_to_push)
		{
			if (tools->a->head->next->index == tools->next_to_fix
				&& tools->a->head->index == tools->next_to_fix + 1)
				swap(tools->a, tools->output);
			if (tools->a->head->index == tools->next_to_fix)
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
	else
	{
		find_index_limit(tools->a, tools, nodes_to_push);
		//printf("limite : %ld\n", tools->limite);
		while (count < nodes_to_push)
		{
			//printf("a head : %ld\n", tools->a->head->index);
			if (tools->a->head->index != 0 && tools->a->head->index < tools->limite)
				push(tools->a, tools->b, tools->output);
			else
				do_rotation(tools->a, tools);
			count++;
		}
		while (tools->a->tail->index != tools->next_to_fix - 1)
			reverse_rotate(tools->a, tools->output);
	}


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
		moves_from_head = INT_MAX;
	trv = src->head;
	moves_from_tail = 1;
	while (trv != NULL)
	{
		moves_from_tail++;
		if (trv->index == next_to_fix)
			moves_from_tail = 1;
		trv = trv->next;
	}
	if (moves_from_tail == (int)src->total_nodes)
		moves_from_tail = INT_MAX;
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
	if (nbr_of_moves >= -5 && nbr_of_moves <= 5)
	{
		if (nbr_of_moves >= 0)
			while (nbr_of_moves-- && !is_node_to_push(tools, src->head->index))
				rotate(src, tools->output);
		else
			while (nbr_of_moves++ && !is_node_to_push(tools, src->head->index))
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
