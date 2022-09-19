/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:49:31 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/16 13:53:33 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_init(t_tools *tools, char **args)
{
	tools->a = malloc(sizeof(t_stack));
	if (tools->a == NULL)
		return (false);
	tools->b = malloc(sizeof(t_stack));
	if (tools->b == NULL)
		return (false);
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
		return (false);
	}
	tools->total_nodes = tools->a->total_nodes;
	tools->next_to_fix = 0;
	return (true);
}

bool	output_init(t_tools *tools)
{
	tools->output = malloc(sizeof(t_output));
	if (tools->output == NULL)
		return (false);
	tools->output->index = 0;
	tools->output->buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tools->output->buff == NULL)
		return (false);
	tools->output->for_cleaning = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tools->output->for_cleaning == NULL)
		return (false);
	tools->output->to_delete = ft_split(DEL, ' ');
	if (tools->output->to_delete == NULL)
		return (false);
	tools->output->to_replace = ft_split(FROM, ' ');
	if (tools->output->to_replace == NULL)
		return (false);
	tools->output->replace_by = ft_split(TO, ' ');
	if (tools->output->replace_by == NULL)
		return (false);
	return (true);
}

bool	nodes_array_init(t_tools *tools)
{
	tools->nodes_array = malloc(sizeof(char) * (tools->total_nodes + 1));
	if (tools->nodes_array == NULL)
		return (false);
	return (true);
}

bool	initialisation(char **args, t_tools *tools)
{
	if (stack_init(tools, args) == false)
		return (false);
	if (nodes_array_init(tools) == false)
	{
		stack_clear(tools);
		return (false);
	}
	if (output_init(tools) == false)
	{
		stack_clear(tools);
		free(tools->nodes_array);
		return (false);
	}
	return (true);
}
