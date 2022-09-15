/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:16:25 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/15 13:15:38 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_bool	is_node_to_push(t_tools *tools, size_t index)
{
	if (index >= tools->limite_low)
		return (TRUE);
	return (FALSE);
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

void	push_nodes(t_stack *src, t_stack *dst, size_t index, t_output *output)
{
	if (found_closest_nodes(src, index) > 0)
		while (src->head->index != index)
			rotate(src, output);
	else
		while (src->head->index != index)
			reverse_rotate(src, output);
	push(src, dst, output);
}
