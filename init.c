/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:49:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 00:41:09 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *a)
{
	t_node	*trv;

	trv = a->head;
	while (trv != a->tail)
	{
		if (trv->nb > a->tail->nb)
			trv->index++;
		else
			a->tail->index++;
		trv = trv->next;
	}
}

t_bool	is_valid_parameter(t_stack *a, int nb)
{
	t_node	*trv;

	trv = a->head;
	while (trv != a->tail)
	{
		if (nb == trv->nb)
			return (FALSE);
		trv = trv->next;
	}
	return (TRUE);
}

t_bool	check_input(t_stack *a, char **args)
{
	size_t	i;
	t_bool	error_flag;
	int		nb;

	error_flag = FALSE;
	i = 1;
	while (args[i] != NULL)
	{
		nb = ft_atoi_with_error_check(args[i], &error_flag);
		if (error_flag == TRUE || is_valid_parameter(a, nb) == FALSE)
			return (FALSE);
		if (add_node_tail(a, new_node(nb)) == FALSE)
			return (FALSE);
		set_index(a);
		i++;
	}
	return (TRUE);
}

t_bool	stack_init(t_stack *a, t_stack *b, char **args)
{
	a->name = STACK_A;
	b->name = STACK_B;
	a->head = NULL;
	b->head = NULL;
	a->tail = NULL;
	b->tail = NULL;
	a->total_nodes = 0;
	b->total_nodes = 0;
	if (!check_input(a, args))
	{
		stack_clear(a);
		return (FALSE);
	}
	return (TRUE);
}
