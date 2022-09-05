/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:33:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/05 17:44:44 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
