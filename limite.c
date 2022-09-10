/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:43:48 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 02:19:32 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index_limit(t_stack *stack, t_tools *tools, size_t nb_nodes)
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
	tools->limite = index_max - ((index_max - index_min) / 2);
}

t_bool	has_nodes_under_limite(t_stack *stack, t_tools *tools)
{
	t_node	*trv;

	trv = stack->head;
	while (trv != NULL && (trv->index != 0 || tools->next_to_fix == 0))
	{
		if (trv->index <= tools->limite)
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
		if (trv->index >= tools->limite)
			return (TRUE);
		trv = trv->next;
	}
	return (FALSE);
}

size_t	all_are_here(t_tools *tools, size_t nodes_to_push)
{
	size_t	i;
	size_t	count;
	t_node	*trv;

	i = 0;
	trv = tools->a->head;
	while (trv->index != 0 && i < nodes_to_push)
	{
		tools->nodes_array[trv->index] = 1;
		trv = trv->next;
		i++;
	}
	i = tools->next_to_fix;
	count = 0;
	while (count < nodes_to_push)
	{
		if (tools->nodes_array[i] == 0)
			return (0);
		count++;
		i++;
	}
	return (count);
}

size_t	calculate_nodes_to_push(t_tools *tools)
{
	size_t	nodes_to_push;
	size_t	result;

	nodes_to_push = 1;
	while (nodes_to_push < tools->total_nodes)
	{
		ft_bzero(tools->nodes_array, sizeof(char) * (tools->total_nodes + 1));
		result = all_are_here(tools, nodes_to_push);
		if (result > 0)
			return (result);
		nodes_to_push++;
	}
	return (tools->total_nodes - tools->next_to_fix);
}

t_bool	set_nodes_array(t_tools *tools)
{
	tools->nodes_array = malloc(sizeof(char) * (tools->total_nodes + 1));
	if (tools->nodes_array == NULL)
		return (FALSE);
	return (TRUE);
}

t_bool	is_node_to_push(t_tools *tools, size_t index)
{
	if (tools->limite_direction == UP && index >= tools->limite)
		return (TRUE);
	if (tools->limite_direction == DOWN && index <= tools->limite)
		return (TRUE);
	return (FALSE);
}
