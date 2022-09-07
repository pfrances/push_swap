/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_fixing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:22:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/07 03:04:05 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, size_t index_to_find)
{
	t_node	*trv;
	ssize_t	count1;
	ssize_t	count2;

	if (src->head == NULL)
		return (FALSE);
	trv = src->head;
	count1 = 0;
	while (trv != NULL && trv->index != index_to_find)
	{
		count1++;
		trv = trv->next;
	}
	if (trv == NULL)
		count1 = INT_MAX;
	trv = src->head;
	count2 = 1;
	while (trv != NULL)
	{
		count2++;
		if (trv->index == index_to_find)
			count2 = 1;
		trv = trv->next;
	}
	if (count2 == src->total_nodes)
		count2 = INT_MAX;
	if (count1 < 5 || count2 < 5)
	{
		if (count1 < count2)
			while (count1--)
				rotate(src);
		else
			while (count2--)
				reverse_rotate(src);
		if (src->head->index == index_to_find)
		{
			push(src, dst);
			rotate(dst);
			return (TRUE);
		}
	}
	return (FALSE);
}

t_bool	fixe_firsts_nodes(t_stack *a, t_stack *b, t_bool *zero_found, size_t index_limit)
{
	if (*zero_found == FALSE)
	{
		if (find_nodes_easy_to_fixe(a, b, 0) == TRUE)
		{
			*zero_found = TRUE;
			return (TRUE);
		}
	}
	else if (b->tail->index < index_limit)
		return (find_nodes_easy_to_fixe(a, b, b->tail->index + 1));
	return (FALSE);
}
