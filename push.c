/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:43:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/05 18:00:00 by pfrances         ###   ########.fr       */
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
