/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:40:55 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/08 23:36:46 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	has_delete_marks(t_output *output)
{
	size_t	i;
	size_t	j;

	if (ft_strchr(output->buff, 'X') == NULL)
		return (FALSE);
	ft_strlcpy(output->for_cleaning, output->buff, BUFFER_SIZE);
	i = 0;
	j = 0;
	ft_bzero(output->buff, BUFFER_SIZE);
	while (output->for_cleaning[i] != '\0')
	{
		if (output->for_cleaning[i] != 'X')
		{
			output->buff[j] = output->for_cleaning[i];
			j++;
		}
		i++;
	}
	ft_bzero(output->for_cleaning, BUFFER_SIZE);
	output->index = j;
	return (TRUE);
}

char	*mark_useless_patterns(t_output *output, size_t *len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (output->to_delete[i] != NULL || i == 0)
	{
		ptr = ft_strnstr(output->buff, output->to_delete[i], output->index);
		if (ptr != NULL)
		{
			*len = ft_strlen(output->to_delete[i]);
			return (ptr);
		}
		i++;
	}
	return (NULL);
}

void	optimise_double_command(t_output *output)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	while (output->to_replace[i] != NULL)
	{
		ptr = ft_strnstr(output->buff, output->to_replace[i], output->index);
		if (ptr != NULL)
		{
			j = 0;
			while (output->replace_by[i][j] != '\0')
			{
				ptr[j] = output->replace_by[i][j];
				j++;
			}
		}
		else
			i++;
	}
	has_delete_marks(output);
}

void	adjust_output(t_output *output)
{
	char	*ptr;
	size_t	len;

	len = 0;
	ptr = mark_useless_patterns(output, &len);
	if (ptr != NULL)
	{
		ft_memset(ptr, 'X', len);
		adjust_output(output);
	}
	else if (has_delete_marks(output))
		adjust_output(output);
	else
	{
		optimise_double_command(output);
		write(STDOUT_FILENO, output->buff, output->index);
		output->index = 0;
	}
}

void	print_remaining(t_output *output)
{
	if (*(output->buff) != '\0')
		adjust_output(output);
}

void	print_to_buff(char *command, t_output *output)
{
	size_t	len;

	len = ft_strlen(command);
	if (output->index >= BUFFER_SIZE - len)
	{
		adjust_output(output);
		ft_bzero(output->buff, BUFFER_SIZE + 1);
		output->index = 0;
	}
	ft_strlcpy(&output->buff[output->index], command, len + 1);
	output->index += len;
}
