/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:43:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 01:22:52 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_src, t_stack *stack_dst)
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
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (stack_dst->name == STACK_B)
		ft_putendl_fd("pb", STDOUT_FILENO);
}

void	swap(t_stack *stack)
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
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (stack->name == STACK_B)
		ft_putendl_fd("sb", STDOUT_FILENO);
}

void	rotate(t_stack *stack)
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
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (stack->name == STACK_B)
		ft_putendl_fd("rb", STDOUT_FILENO);
}

void	reverse_rotate(t_stack *stack)
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
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (stack->name == STACK_B)
		ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	sort_five_and_push(t_stack *src, t_stack *dst)
{
	up_to_five_nodes(src, dst);
	while (src->total_nodes > 0)
	{
		push(src, dst);
		rotate(dst);
	}
}
