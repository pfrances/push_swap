/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/08 15:35:29 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STACK_A 0
# define STACK_B 1
# define BUFFER_SIZE 1024
# define TO_DELETE "pa\npb\n pb\npa\n \nra\nrra rra\nra\n \nrb\nrrb rrb\nrb\n sa\nsa\n sb\nsb\n"
# define TO_REPLACE "\nra\nrb \nrb\nra rra\nrrb rrb\nrra sa\nsb sb\nsa"
# define REPLACE_BY "\nrrXXX \nrrXXX rrrXXXX rrrXXXX ssXXX ssXXX"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

typedef enum e_direction
{
	UP,
	DOWN
}		t_direction;

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

typedef struct s_limite
{
	size_t		value;
	t_bool		zero_is_found;
	t_direction	direction;
}		t_limite;

typedef struct s_output
{
	size_t		index;
	char		*buff;
	char		*for_cleaning;
	char		**to_delete;
	char		**to_replace;
	char		**replace_by;
}		t_output;

/*			push_swap.c				*/
void	print_lists(t_stack *a, t_stack *b);

/*			init.c					*/
t_bool	stack_init(t_stack *a, t_stack *b, char **args);
t_bool	output_init(t_output *output);

/*			atoi_error_check.c		*/
int		ft_atoi_with_error_check(const char *nptr, t_bool *error_flag);

/*			stacks.c				*/
t_node	*new_node(int nb);
t_bool	add_node_tail(t_stack *stack, t_node *new);
t_bool	is_full_sorted(t_stack *stack);
void	stack_clear(t_stack *stack);
void	update_tail(t_stack *stack);

/*			commands.c				*/
void	swap(t_stack *stack, t_output *output);
void	push(t_stack *stack_src, t_stack *stack_dst, t_output *output);
void	rotate(t_stack *stack, t_output *output);
void	reverse_rotate(t_stack *stack, t_output *output);
void	sort_five_and_push(t_stack *src, t_stack *dst, t_output *output);
void	do_rotation(t_stack *stack, t_limite limite, t_output *output);

/*			resolver.c				*/
void	resolver(t_stack *a, t_stack *b, t_output *output);
void	keep_half(t_stack *a, t_stack *b, t_output *output);
size_t	find_index_limit(t_stack *stack);

/*			up_to_five_nodes.c		*/
void	up_to_five_nodes(t_stack *src, t_stack *dst, t_output *output);

/*			nodes_fixing.c			*/
void	fixe_sorted_node(t_stack *a, t_stack *b, t_limite limite, t_output *output);
t_bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, size_t index_to_find, t_limite limite, t_output *output);
t_bool	fixe_firsts_nodes(t_stack *a, t_stack *b, t_limite limite, t_output *output);

/*			output.c				*/
void	print_to_buff(char *command, t_output *output);
void	print_remaining(t_output *output);

#endif