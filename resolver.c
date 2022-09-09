/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:57:37 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/09 03:09:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_index_limit(t_stack *stack, t_tools *tools)
{
	size_t	index_min;
	size_t	index_max;
	t_node	*trv;

	trv = stack->head;
	index_min = INT_MAX;
	index_max = 0;
	while (trv != NULL)
	{
		if (tools->next_to_fix != 0 && trv->index == 0 && stack->name == STACK_A)
			break ;
		if (trv->index < index_min)
			index_min = trv->index;
		if (trv->index > index_max)
			index_max = trv->index;
		trv = trv->next;
	}
	return (index_max - ((index_max - index_min) / 2));
}

// size_t	find_index_limit(t_stack *stack, t_tools *tools)
// {
// 	size_t	i;
// 	size_t	count;
// 	t_node	*trv;

// 	i = 0;
// 	trv = stack->head;
// 	while (tools->limites_array[i] != 0 && tools->next_to_fix == 0 || trv->index != 0)
// 	{
// 		if (trv->index < tools->limites_array[i])
// 		{
// 			break ;
// 			trv = stack->head;
// 		}
// 		trv = trv->next;
// 		if (trv == NULL)
// 		{
// 			trv = stack->head;
// 			i++;
// 		}
// 	}
// 	if (tools->limites_array[i] != 0)
// 		return (tools->limites_array[i]);
// 	i = 0;
// 	trv = stack->head;
// 	while (tools->limites_array[i] != 0 && tools->next_to_fix == 0 || trv->index != 0)
// 	{
// 		if ((trv->index <= tools->total_nodes - tools->limites_array[i]))
// 		{
// 			break ;
// 			trv = stack->head;
// 		}
// 		trv = trv->next;
// 		if (trv == NULL)
// 		{
// 			trv = stack->head;
// 			i++;
// 		}
// 	}
// 	return (tools->limites_array[i]);
// }

void	keep_half(t_tools *tools)
{
	size_t		nodes_to_push;
	size_t		count;

	if (tools->b->total_nodes <= 5)
	{
		sort_five_and_push(tools->b, tools->a, tools->output);
		return (fixe_sorted_node(tools));
	}
	nodes_to_push = (tools->b->total_nodes / 2) + (tools->b->total_nodes % 2 == 1);
	tools->limite_direction = UP;
	tools->limite_value_a = find_index_limit(tools->b, tools);
	count = 0;
	while (tools->b->head != NULL && count < nodes_to_push)
	{
		find_nodes_easy_to_fixe(tools->b, tools->a, tools);
		if (tools->b->head != NULL && tools->b->head->index > tools->limite_value_a)
		{
			push(tools->b, tools->a, tools->output);
			count++;
		}
		else
			do_rotation(tools->b, tools);
	}
	keep_half(tools);
}

void	second_step(t_tools *tools)
{
	reverse_rotate(tools->b, tools->output);
	push(tools->b, tools->a, tools->output);
	while (tools->b->tail->index == tools->a->head->index - 1)
	{
		reverse_rotate(tools->b, tools->output);
		push(tools->b, tools->a, tools->output);
	}
	while (tools->a->head->index < tools->limite_value_a)
		rotate(tools->a, tools->output);
	keep_half(tools);
}

void	resolver(t_tools *tools)
{
	size_t		nodes_to_push;

	if (is_full_sorted(tools->a))
		return ;
	if (tools->total_nodes <= 5)
		up_to_five_nodes(tools->a, tools->b, tools->output);
	else
	{
		nodes_to_push = (tools->total_nodes / 2);
		tools->limite_direction = DOWN;
		tools->limite_value_a = find_index_limit(tools->a, tools);
		tools->limite_value_b = find_index_limit(tools->a, tools);
		while (tools->b->total_nodes < nodes_to_push)
		{
			find_nodes_easy_to_fixe(tools->a, tools->b, tools);
			if (tools->a->head->index < tools->limite_value_a)
				push(tools->a, tools->b, tools->output);
			else
				do_rotation(tools->a, tools);
		}
		second_step(tools);
	}
}
