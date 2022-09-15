/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:25:05 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/15 13:15:31 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_index(t_stack *stack, size_t to_find)
{
	t_node	*trv1;
	t_node	*trv2;
	size_t	count;

	trv1 = stack->head;
	while (trv1 != NULL)
	{
		count = 0;
		trv2 = stack->head;
		while (trv2 != NULL)
		{
			if (trv1->index > trv2->index && trv1 != trv2)
				count++;
			trv2 = trv2->next;
		}
		if (count == to_find)
			return (trv1->index);
		trv1 = trv1->next;
	}
	if (trv1 == NULL)
		return (INT_MAX);
	return (0);
}

size_t	ft_abs(int nb)
{
	if (nb < 0)
		return ((size_t)(-nb));
	return ((size_t)(nb));
}
