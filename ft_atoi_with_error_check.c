/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_with_error_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:31:06 by pfrances          #+#    #+#             */
/*   Updated: 2022/08/16 16:44:34 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static char	*check_sign(char *str_nbr, int *sign)
{
	if (*str_nbr == '+')
		return (str_nbr + 1);
	else if (*str_nbr == '-')
	{
		*sign = -1;
		return (str_nbr + 1);
	}
	else
		return (str_nbr);
}

int	ft_atoi_with_error_check(const char *nptr, t_bool *error_flag)
{
	long	result;
	int		sign;
	char	*str_nbr;

	str_nbr = (char *)nptr;
	while (ft_is_space(*str_nbr))
		str_nbr++;
	sign = 1;
	str_nbr = check_sign(str_nbr, &sign);
	result = 0;
	while (*str_nbr != '\0' && ft_isdigit(*str_nbr))
	{
		result = result * 10 + (*str_nbr - '0');
		str_nbr++;
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
		{
			*error_flag = TRUE;
			return (0);
		}
	}
	if (*str_nbr != '\0')
		*error_flag = TRUE;
	return ((int)(result * sign));
}
