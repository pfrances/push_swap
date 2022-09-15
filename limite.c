/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:43:48 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/15 11:40:58 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_limit(t_stack *stack, t_tools *tools, size_t nb_nodes)
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
	tools->limite_high = index_max - ((index_max - index_min) / 3);
	tools->limite_low = index_max - (((index_max - index_min) / 3) * 2);
}

t_bool	has_nodes_under_limite(t_stack *stack, t_tools *tools)
{
	t_node	*trv;

	trv = stack->head;
	while (trv != NULL && (trv->index != 0 || tools->next_to_fix == 0))
	{
		if (trv->index <= tools->limite_high)
			return (TRUE);
		trv = trv->next;
	}
	return (FALSE);
}

t_bool	has_nodes_over_limite(t_stack *stack, t_tools *tools)
{
	t_node	*trv;

	trv = stack->head;
	while (trv != NULL && (trv->index != 0 || tools->next_to_fix == 0))
	{
		if (trv->index >= tools->limite_low)
			return (TRUE);
		trv = trv->next;
	}
	return (FALSE);
}
