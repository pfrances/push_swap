/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:43:48 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/09 02:18:38 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	set_limites_array(t_tools *tools)
{
	size_t	i;
	size_t	limite;

	i = 0;
	limite = tools->total_nodes;
	while (limite / 2 > 5)
	{
		limite = limite / 2;
		i++;
	}
	tools->limites_array = malloc(sizeof(size_t) * i + 1);
	if (tools->limites_array == NULL)
		return (FALSE);
	i = 0;
	limite = tools->total_nodes;
	while (limite / 2 > 5)
	{
		limite = limite / 2;
		tools->limites_array[i] = limite;
		i++;
	}
	tools->limites_array[i] = 0;
	return (TRUE);
}