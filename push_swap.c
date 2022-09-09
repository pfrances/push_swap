/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:44:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/09 02:03:20 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_stack *a, t_stack *b)
{
	t_node	*trv;

	ft_putstr_fd("-> a :\n", 1);
	trv = a->head;
	while (trv != NULL)
	{
		printf("nb : %d : (%ld)\n", trv->nb, trv->index);
		trv = trv->next;
	}
	ft_putstr_fd("-> b : \n", 1);
	trv = b->head;
	while (trv != NULL)
	{
		printf("nb : %d : (%ld)\n", trv->nb, trv->index);
		trv = trv->next;
	}
	ft_putstr_fd("\n\n", 1);
}

void	free_memory(t_tools *tools)
{
	size_t	i;

	stack_clear(tools);
	free(tools->output->buff);
	free(tools->output->for_cleaning);
	i = 0;
	while (tools->output->to_delete[i] != NULL)
		free(tools->output->to_delete[i++]);
	free(tools->output->to_delete);
	i = 0;
	while (tools->output->to_replace[i] != NULL)
		free(tools->output->to_replace[i++]);
	free(tools->output->to_replace);
	i = 0;
	while (tools->output->replace_by[i] != NULL)
		free(tools->output->replace_by[i++]);
	free(tools->output->replace_by);
	free(tools->output);
	free(tools->limites_array);
}

int	main(int __attribute__((unused))argc, char *argv[])
{
	t_tools	tools;

	if (!stack_init(&tools, argv) || !output_init(&tools) || !set_limites_array(&tools))
		ft_putendl_fd("Error\n", STDERR_FILENO);
	else if (tools.a->total_nodes)
	{
		resolver(&tools);
		print_remaining(tools.output);
		free_memory(&tools);
	}
	return (0);
}
