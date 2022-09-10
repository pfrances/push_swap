/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:49:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/11 00:36:51 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!input_check(tools->a, args))
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

t_bool	nodes_array_init(t_tools *tools)
{
	tools->nodes_array = malloc(sizeof(char) * (tools->total_nodes + 1));
	if (tools->nodes_array == NULL)
		return (FALSE);
	return (TRUE);
}

t_bool	initialisation(char **args, t_tools *tools)
{
	if (stack_init(tools, args) == FALSE)
		return (FALSE);
	if (nodes_array_init(tools) == FALSE)
	{
		stack_clear(tools);
		return (FALSE);
	}
	if (output_init(tools) == FALSE)
	{
		stack_clear(tools);
		free(tools->nodes_array);
		return (FALSE);
	}
	return (TRUE);
}
