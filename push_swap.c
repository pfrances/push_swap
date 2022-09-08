/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:44:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/08 13:05:35 by pfrances         ###   ########.fr       */
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

int	main(int __attribute__((unused))argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_output	output;

	if (!stack_init(&a, &b, argv) || !output_init(&output))
		ft_putendl_fd("Error\n", STDERR_FILENO);
	else if (a.total_nodes)
	{
		resolver(&a, &b, &output);
		//print_lists(&a, &b);
		stack_clear(&a);
		stack_clear(&b);
		print_remaining(&output);
	}
	return (0);
}
