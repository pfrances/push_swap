/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_five_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:22:12 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/07 22:22:35 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args_resolver(t_stack *stack, t_output *output)
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

void	four_args_resolver(t_stack *src, t_stack *dst, t_output *output)
{
	push(src, dst, output);
	three_args_resolver(src, output);
	if (dst->head->nb < src->head->nb)
		push(dst, src, output);
	else if (dst->head->nb > src->tail->nb)
	{
		push(dst, src, output);
		rotate(src, output);
	}
	else if (dst->head->nb < src->head->next->nb)
	{
		push(dst, src, output);
		swap(src, output);
	}
	else
	{
		reverse_rotate(src, output);
		push(dst, src, output);
		rotate(src, output);
		rotate(src, output);
	}
}

void	five_args_resolver_end(t_stack *src, t_stack *dst, t_output *output)
{
	if (dst->head->nb > src->head->next->next->nb)
	{
		reverse_rotate(src, output);
		push(dst, src, output);
		rotate(src, output);
		rotate(src, output);
	}
	else
	{
		rotate(src, output);
		rotate(src, output);
		push(dst, src, output);
		reverse_rotate(src, output);
		reverse_rotate(src, output);
	}
}

void	five_args_resolver(t_stack *src, t_stack *dst, t_output *output)
{
	push(src, dst, output);
	four_args_resolver(src, dst, output);
	if (dst->head->nb < src->head->nb)
		push(dst, src, output);
	else if (dst->head->nb > src->tail->nb)
	{
		push(dst, src, output);
		rotate(src, output);
	}
	else if (dst->head->nb > src->head->nb
		&& dst->head->nb < src->head->next->nb)
	{
		push(dst, src, output);
		swap(src, output);
	}
	else
		five_args_resolver_end(src, dst, output);
}

void	up_to_five_nodes(t_stack *src, t_stack *dst, t_output *output)
{
	if (is_full_sorted(src) || src->total_nodes > 5)
		return ;
	if (src->total_nodes == 2)
		swap(src, output);
	else if (src->total_nodes == 3)
		three_args_resolver(src, output);
	else if (src->total_nodes == 4)
		four_args_resolver(src, dst, output);
	else if (src->total_nodes == 5)
		five_args_resolver(src, dst, output);
	return ;
}
