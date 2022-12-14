/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:43:44 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/08 23:50:47 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int nb)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->nb = nb;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	update_tail(t_stack *stack)
{
	t_node	*trv;

	if (stack->head == NULL)
		stack->tail = NULL;
	else
	{
		trv = stack->head;
		while (trv->next != NULL && trv->next != stack->head)
			trv = trv->next;
		stack->tail = trv;
		stack->tail->next = NULL;
	}
}

t_bool	add_node_tail(t_stack *stack, t_node *new)
{
	if (new == NULL)
		return (FALSE);
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->total_nodes += 1;
	return (TRUE);
}

t_bool	is_full_sorted(t_stack *stack)
{
	t_node	*trv;

	if (stack->head == NULL)
		return (TRUE);
	trv = stack->head;
	while (trv->next != NULL)
	{
		if (trv->nb > trv->next->nb)
			return (FALSE);
		trv = trv->next;
	}
	return (TRUE);
}

void	stack_clear(t_tools *tools)
{
	t_node	*trv;
	t_node	*tmp;

	trv = tools->a->head;
	while (trv != NULL)
	{
		tmp = trv->next;
		free(trv);
		trv = tmp;
	}
	free(tools->a);
	trv = tools->b->head;
	while (trv != NULL)
	{
		tmp = trv->next;
		free(trv);
		trv = tmp;
	}
	free(tools->b);
}
