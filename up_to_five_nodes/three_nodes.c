/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:47:38 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 16:01:07 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_nodes_resolver(t_stack *stack, t_output *output)
{
	if (is_full_sorted(stack))
		return ;
	if (stack->head->nb > stack->head->next->nb
		&& stack->head->nb < stack->tail->nb)
		swap(stack, output);
	else if (stack->head->nb > stack->head->next->nb
		&& stack->head->next->nb > stack->tail->nb)
	{
		swap(stack, output);
		reverse_rotate(stack, output);
	}
	else if (stack->head->nb > stack->head->next->nb
		&& stack->head->nb > stack->tail->nb)
		rotate(stack, output);
	else if (stack->head->nb < stack->head->next->nb
		&& stack->head->nb < stack->tail->nb)
	{
		swap(stack, output);
		rotate(stack, output);
	}
	else
		reverse_rotate(stack, output);
}
