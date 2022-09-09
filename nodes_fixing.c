/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_fixing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:22:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/09 03:08:43 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	fixe_sorted_node(t_stack *a, t_stack *b, t_limite limite, t_output *output)
// {
// 	size_t	count;
// 	size_t	nodes_to_push;

// 	keep_half(a, b, output);
// 	count = 0;
// 	nodes_to_push = (limite.value - a->tail->index) - 1;
// 	while (a->head->index > 0 && count < nodes_to_push)
// 	{
// 		if (a->head->index == a->tail->index + 1)
// 			rotate(a, output);
// 		else
// 			push(a, b, output);
// 		count++;
// 	}
// 	keep_half(a, b, output);
// }

void	fixe_sorted_node(t_tools *tools)
{
	while (tools->a->head->index < tools->limite_value_b && tools->a->head->index != 0)
	{
		if (tools->a->head->next->index == tools->next_to_fix)
			swap(tools->a, tools->output);
		if (tools->a->head->index == tools->next_to_fix)
		{
			rotate(tools->a, tools->output);
			tools->next_to_fix++;
		}
		else
			push(tools->a, tools->b, tools->output);
	}
	tools->limite_value_b = tools->total_nodes - ((tools->total_nodes - tools->next_to_fix) / 2);
	if (tools->limite_value_b >= tools->next_to_fix)
		tools->limite_value_b = tools->total_nodes;
	if (tools->b->total_nodes != 0)
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
	if (nbr_of_moves != -INT_MAX && nbr_of_moves != INT_MAX)
	{
		if (nbr_of_moves >= 0)
			while (nbr_of_moves--
				&& ((tools->limite_direction == UP && src->head->index <= tools->limite_value_a)
				|| (tools->limite_direction == DOWN && src->head->index >= tools->limite_value_a)))
				rotate(src, tools->output);
		else
			while (nbr_of_moves++
				&& ((tools->limite_direction == UP && src->head->index <= tools->limite_value_a)
				|| (tools->limite_direction == DOWN && src->head->index >= tools->limite_value_a)))
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
