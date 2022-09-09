/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:49:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/09 00:20:23 by pfrances         ###   ########.fr       */
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

t_bool	stack_init(t_tools *tools, char **args)
{
	tools->a = malloc(sizeof(t_stack));
	if (tools->a == NULL)
		return (FALSE);
	tools->b = malloc(sizeof(t_stack));
	if (tools->b == NULL)
		return (FALSE);
	tools->a->name = STACK_A;
	tools->b->name = STACK_B;
	tools->a->head = NULL;
	tools->b->head = NULL;
	tools->a->tail = NULL;
	tools->b->tail = NULL;
	tools->a->total_nodes = 0;
	tools->b->total_nodes = 0;
	if (!check_input(tools->a, args))
	{
		stack_clear(tools);
		return (FALSE);
	}
	tools->total_nodes = tools->a->total_nodes;
	tools->next_to_fix = 0;
	return (TRUE);
}

t_bool	output_init(t_tools *tools)
{
	tools->output = malloc(sizeof(t_output));
	if (tools->output == NULL)
		return (FALSE);
	tools->output->index = 0;
	tools->output->buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tools->output->buff == NULL)
		return (FALSE);
	tools->output->for_cleaning = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tools->output->for_cleaning == NULL)
		return (FALSE);
	tools->output->to_delete = ft_split(TO_DELETE, ' ');
	if (tools->output->to_delete == NULL)
		return (FALSE);
	tools->output->to_replace = ft_split(TO_REPLACE, ' ');
	if (tools->output->to_replace == NULL)
		return (FALSE);
	tools->output->replace_by = ft_split(REPLACE_BY, ' ');
	if (tools->output->replace_by == NULL)
		return (FALSE);
	return (TRUE);
}
