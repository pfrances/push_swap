/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:10:11 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/15 13:12:58 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	all_are_here(t_tools *tools, size_t nodes_to_push)
{
	size_t	i;
	size_t	count;
	t_node	*trv;

	i = 0;
	trv = tools->a->head;
	while (trv != NULL && trv->index != 0 && i < nodes_to_push)
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

	nodes_to_push = 3;
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
