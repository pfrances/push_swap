/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_fixing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:22:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/08 13:22:51 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fixe_sorted_node(t_stack *a, t_stack *b, t_limite limite, t_output *output)
{
	size_t	count;
	size_t	nodes_to_push;

	keep_half(a, b, output);
	count = 0;
	nodes_to_push = (limite.value - a->tail->index) - 1;
	while (a->head->index > 0 && count < nodes_to_push)
	{
		if (a->head->index == a->tail->index + 1)
			rotate(a, output);
		else
			push(a, b, output);
		count++;
	}
	keep_half(a, b, output);
}

int	found_closest_nodes(t_stack *src, size_t index_to_find)
{
	int		moves_from_head;
	int		moves_from_tail;
	t_node	*trv;

	trv = src->head;
	moves_from_head = 0;
	while (trv != NULL && trv->index != index_to_find)
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
		if (trv->index == index_to_find)
			moves_from_tail = 1;
		trv = trv->next;
	}
	if (moves_from_tail == (int)src->total_nodes)
		moves_from_tail = INT_MAX;
	if (moves_from_head < moves_from_tail)
		return (moves_from_head);
	return (-moves_from_tail);
}

t_bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, size_t index_to_find, t_limite limite, t_output *output)
{
	int	nbr_of_moves;

	nbr_of_moves = found_closest_nodes(src, index_to_find);
	if (nbr_of_moves != -INT_MAX && nbr_of_moves != INT_MAX)
	{
		if (nbr_of_moves >= 0)
			while (nbr_of_moves--
				&& ((limite.direction == UP && src->head->index <= limite.value)
				|| (limite.direction == DOWN && src->head->index >= limite.value)))
				rotate(src, output);
		else
			while (nbr_of_moves++
				&& ((limite.direction == UP && src->head->index <= limite.value)
				|| (limite.direction == DOWN && src->head->index >= limite.value)))
				reverse_rotate(src, output);
		if (src->head->index == index_to_find)
		{
			push(src, dst, output);
			rotate(dst, output);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	fixe_firsts_nodes(t_stack *a, t_stack *b, t_limite limite, t_output *output)
{
	if (limite.zero_is_found == FALSE)
	{
		if (find_nodes_easy_to_fixe(a, b, 0, limite, output) == TRUE)
		{
			limite.zero_is_found = TRUE;
			return (TRUE);
		}
	}
	else if (b->tail->index < limite.value)
		return (find_nodes_easy_to_fixe(a, b, b->tail->index + 1, limite, output));
	return (FALSE);
}
