/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:44:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 17:59:11 by pfrances         ###   ########.fr       */
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
	t_stack	a;
	t_stack	b;

	if (!stack_init(&a, &b, argv))
		ft_putendl_fd("Error\n", STDERR_FILENO);
	else if (a.total_nodes)
	{
		resolver(&a, &b);
		//print_lists(&a, &b);
		stack_clear(&a);
		stack_clear(&b);
	}
	return (0);
}
