/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:21:59 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 22:22:32 by pfrances         ###   ########.fr       */
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

t_bool	input_check(t_stack *a, char **args)
{
	size_t	i;
	t_bool	error_flag;
	int		nb;

	i = 1;
	while (args[i] != NULL)
	{
		error_flag = TRUE;
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
