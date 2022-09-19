/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:47:23 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/16 13:53:07 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_first(t_stack *src, t_stack *dst,
	size_t first, t_output *output)
{
	push_nodes(src, dst, first, output);
	four_nodes_resolver(src, dst, output);
	push(dst, src, output);
}

static void	push_second(t_stack *src, t_stack *dst,
	size_t second, t_output *output)
{
	push_nodes(src, dst, second, output);
	four_nodes_resolver(src, dst, output);
	swap(dst, output);
	push(dst, src, output);
}

static void	push_last(t_stack *src, t_stack *dst,
	size_t last, t_output *output)
{
	push_nodes(src, dst, last, output);
	four_nodes_resolver(src, dst, output);
	push(dst, src, output);
	rotate(src, output);
}

void	five_nodes_resolver(t_stack *src, t_stack *dst, t_output *output)
{
	size_t	first;
	size_t	second;
	size_t	last;

	first = find_index(src, 0);
	second = find_index(src, 1);
	last = find_index(src, 4);
	if (first <= last && first <= second)
		push_first(src, dst, first, output);
	else if (last < second)
		push_last(src, dst, last, output);
	else
		push_second(src, dst, second, output);
}
