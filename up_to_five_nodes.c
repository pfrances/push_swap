/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_five_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:22:12 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 01:15:14 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args_resolver(t_stack *stack)
{
	if (is_full_sorted(stack))
		return ;
	if (stack->head->nb > stack->head->next->nb
		&& stack->head->nb < stack->tail->nb)
		swap(stack);
	else if (stack->head->nb > stack->head->next->nb
		&& stack->head->next->nb > stack->tail->nb)
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (stack->head->nb > stack->head->next->nb
		&& stack->head->nb > stack->tail->nb)
		rotate(stack);
	else if (stack->head->nb < stack->head->next->nb
		&& stack->head->nb < stack->tail->nb)
	{
		swap(stack);
		rotate(stack);
	}
	else
		reverse_rotate(stack);
}

void	four_args_resolver(t_stack *src, t_stack *dst)
{
	push(src, dst);
	three_args_resolver(src);
	if (dst->head->nb < src->head->nb)
		push(dst, src);
	else if (dst->head->nb > src->tail->nb)
	{
		push(dst, src);
		rotate(src);
	}
	else if (dst->head->nb < src->head->next->nb)
	{
		push(dst, src);
		swap(src);
	}
	else
	{
		reverse_rotate(src);
		push(dst, src);
		rotate(src);
		rotate(src);
	}
}

void	five_args_resolver_end(t_stack *src, t_stack *dst)
{
	if (dst->head->nb > src->head->next->next->nb)
	{
		reverse_rotate(src);
		push(dst, src);
		rotate(src);
		rotate(src);
	}
	else
	{
		rotate(src);
		rotate(src);
		push(dst, src);
		reverse_rotate(src);
		reverse_rotate(src);
	}
}

void	five_args_resolver(t_stack *src, t_stack *dst)
{
	push(src, dst);
	four_args_resolver(src, dst);
	if (dst->head->nb < src->head->nb)
		push(dst, src);
	else if (dst->head->nb > src->tail->nb)
	{
		push(dst, src);
		rotate(src);
	}
	else if (dst->head->nb > src->head->nb
		&& dst->head->nb < src->head->next->nb)
	{
		push(dst, src);
		swap(src);
	}
	else
		five_args_resolver_end(src, dst);
}

void	up_to_five_nodes(t_stack *src, t_stack *dst)
{
	if (is_full_sorted(src) || src->total_nodes > 5)
		return ;
	if (src->total_nodes == 2)
		swap(src);
	else if (src->total_nodes == 3)
		three_args_resolver(src);
	else if (src->total_nodes == 4)
		four_args_resolver(src, dst);
	else if (src->total_nodes == 5)
		five_args_resolver(src, dst);
	return ;
}
