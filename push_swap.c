/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:44:14 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 01:30:21 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
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
		ft_putendl_fd("ERROR\n", STDERR_FILENO);
	else if (a.total_nodes)
		resolver(&a, &b);
	print_lists(&a, &b);
	return (0);
}
// ERROR : ./push_swap -697 -681 -606 -86 312 -130 772 81 -385 175 -70 301
