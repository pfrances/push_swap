/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:44:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 22:38:57 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(tools->nodes_array);
}

int	print_error_and_quit(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (1);
}

int	main(int __attribute__((unused))argc, char *argv[])
{
	t_tools	tools;

	if (initialisation(argv, &tools) == FALSE)
		return (print_error_and_quit());
	else if (tools.a->total_nodes)
	{
		resolver(&tools);
		print_remaining(tools.output);
		free_memory(&tools);
	}
	return (0);
}
