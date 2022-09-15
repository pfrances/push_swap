/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:47:34 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/13 18:29:36 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	four_nodes_resolver(t_stack *src, t_stack *dst, t_output *output)
{
	size_t	first;
	size_t	second;
	size_t	last;

	first = find_index(src, 0);
	second = find_index(src, 1);
	last = find_index(src, 3);
	if (first <= last && first <= second)
		push_nodes(src, dst, first, output);
	else if (last < second)
		push_nodes(src, dst, last, output);
	else
		push_nodes(src, dst, second, output);
	three_nodes_resolver(src, output);
	push(dst, src, output);
	if (src->head->index == last)
		rotate(src, output);
	else if (src->head->index == second)
		swap(src, output);
}
