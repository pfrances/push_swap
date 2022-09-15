/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:43:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/15 11:25:29 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	push(t_stack *stack_src, t_stack *stack_dst, t_output *output)
{
	t_node	*tmp;

	if (stack_src->head == NULL)
		return (0);
	tmp = stack_dst->head;
	stack_dst->head = stack_src->head;
	stack_src->head = stack_src->head->next;
	stack_dst->head->next = tmp;
	update_tail(stack_src);
	update_tail(stack_dst);
	stack_src->total_nodes -= 1;
	stack_dst->total_nodes += 1;
	if (stack_dst->name == STACK_A)
		print_to_buff("pa\n", output);
	else if (stack_dst->name == STACK_B)
		print_to_buff("pb\n", output);
	return (1);
}

size_t	swap(t_stack *stack, t_output *output)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head == stack->tail)
		return (0);
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	update_tail(stack);
	if (stack->name == STACK_A)
		print_to_buff("sa\n", output);
	else if (stack->name == STACK_B)
		print_to_buff("sb\n", output);
	return (1);
}

size_t	rotate(t_stack *stack, t_output *output)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head == stack->tail)
		return (0);
	tmp = stack->head->next;
	stack->tail->next = stack->head;
	stack->head->next = NULL;
	stack->head = tmp;
	update_tail(stack);
	if (stack->name == STACK_A)
		print_to_buff("ra\n", output);
	else if (stack->name == STACK_B)
		print_to_buff("rb\n", output);
	return (1);
}

size_t	reverse_rotate(t_stack *stack, t_output *output)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head == stack->tail)
		return (0);
	tmp = stack->head;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->head->next = tmp;
	update_tail(stack);
	if (stack->name == STACK_A)
		print_to_buff("rra\n", output);
	else if (stack->name == STACK_B)
		print_to_buff("rrb\n", output);
	return (1);
}
