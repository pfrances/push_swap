/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_five_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:22:12 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/14 01:46:21 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	up_to_five_nodes(t_stack *src, t_stack *dst, t_output *output)
{
	if (is_full_sorted(src))
		return ;
	if (src->total_nodes == 2)
		rotate(src, output);
	else if (src->total_nodes == 3)
		three_nodes_resolver(src, output);
	else if (src->total_nodes == 4)
		four_nodes_resolver(src, dst, output);
	else if (src->total_nodes == 5)
		five_nodes_resolver(src, dst, output);
	return ;
}

void	sort_five_and_push(t_stack *src, t_stack *dst, t_tools *tools)
{
	if (tools->next_to_fix != 0)
		up_to_five_nodes(src, dst, tools->output);
	while (src->total_nodes > 0)
	{
		push(src, dst, tools->output);
		if (dst->head->index == tools->next_to_fix)
		{
			rotate(dst, tools->output);
			tools->next_to_fix++;
		}
	}
}
