/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:43:36 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/05 17:42:46 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
