/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:43:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/07 22:53:10 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_src, t_stack *stack_dst, t_output *output)
{
	t_node	*tmp;

	if (stack_src->head == NULL)
		return ;
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
}

void	swap(t_stack *stack, t_output *output)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head == stack->tail)
		return ;
	tmp = stack->head;
	stack->head = stack->head->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	update_tail(stack);
	if (stack->name == STACK_A)
		print_to_buff("sa\n", output);
	else if (stack->name == STACK_B)
		print_to_buff("sb\n", output);
}

void	rotate(t_stack *stack, t_output *output)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head == stack->tail)
		return ;
	tmp = stack->head->next;
	stack->tail->next = stack->head;
	stack->head->next = NULL;
	stack->head = tmp;
	update_tail(stack);
	if (stack->name == STACK_A)
		print_to_buff("ra\n", output);
	else if (stack->name == STACK_B)
		print_to_buff("rb\n", output);
}

void	reverse_rotate(t_stack *stack, t_output *output)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head == stack->tail)
		return ;
	tmp = stack->head;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->head->next = tmp;
	update_tail(stack);
	if (stack->name == STACK_A)
		print_to_buff("rra\n", output);
	else if (stack->name == STACK_B)
		print_to_buff("rrb\n", output);
}

void	sort_five_and_push(t_stack *src, t_stack *dst, t_output *output)
{
	up_to_five_nodes(src, dst, output);
	while (src->total_nodes > 0)
	{
		push(src, dst, output);
		rotate(dst, output);
	}
}

void	do_rotation(t_stack *stack, t_limite limite, t_output *output)
{
	t_node	*trv;
	size_t	count1;
	size_t	count2;

	trv = stack->head;
	count1 = 0;
	while (trv != NULL
		&& ((limite.direction == UP && trv->index <= limite.value)
		|| (limite.direction == DOWN && trv->index >= limite.value)))
	{
		trv = trv->next;
		count1++;
	}
	trv = stack->head;
	count2 = 1;
	while (trv != NULL)
	{
		count2++;
		if ((limite.direction == UP && trv->index > limite.value)
			|| (limite.direction == DOWN && trv->index < limite.value))
			count2 = 1;
		trv = trv->next;
	}
	if (count1 < count2)
		rotate(stack, output);
	else
		reverse_rotate(stack, output);
}
