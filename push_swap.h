/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/06 01:23:08 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STACK_A 0
# define STACK_B 1
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

typedef struct s_node
{
	size_t			index;
	int				nb;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int				name;
	size_t			total_nodes;
	struct s_node	*head;
	struct s_node	*tail;
}		t_stack;

/*			push_swap.c				*/
void	print_lists(t_stack *a, t_stack *b);

/*			init.c					*/
t_bool	stack_init(t_stack *a, t_stack *b, char **args);
void	up_to_five_nodes(t_stack *src, t_stack *dst);

/*			atoi_error_check.c		*/
int		ft_atoi_with_error_check(const char *nptr, t_bool *error_flag);

/*			stacks.c				*/
t_node	*new_node(int nb);
t_bool	add_node_tail(t_stack *stack, t_node *new);
t_bool	is_full_sorted(t_stack *stack);
void	stack_clear(t_stack *stack);
void	update_tail(t_stack *stack);

/*			commands.c				*/
void	swap(t_stack *stack);
void	push(t_stack *stack_src, t_stack *stack_dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	sort_five_and_push(t_stack *src, t_stack *dst);

/*			resolver.c				*/
void	resolver(t_stack *a, t_stack *b);
void	keep_half(t_stack *a, t_stack *b);

#endif