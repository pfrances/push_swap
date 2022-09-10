/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:40:55 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/10 22:28:54 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_remaining(t_output *output)
{
	if (*(output->buff) != '\0')
		output_optimisation(output);
}

void	print_to_buff(char *command, t_output *output)
{
	size_t	len;

	len = ft_strlen(command);
	if (output->index >= BUFFER_SIZE - len)
	{
		output_optimisation(output);
		ft_bzero(output->buff, BUFFER_SIZE + 1);
		output->index = 0;
	}
	ft_strlcpy(&output->buff[output->index], command, len + 1);
	output->index += len;
}
