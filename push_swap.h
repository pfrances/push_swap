/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/11 00:57:48 by pfrances         ###   ########.fr       */
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

typedef struct s_output
{
	size_t		index;
	char		*buff;
	char		*for_cleaning;
	char		**to_delete;
	char		**to_replace;
	char		**replace_by;
}		t_output;

typedef struct s_tools
{
	t_output	*output;
	t_stack		*a;
	t_stack		*b;
	size_t		total_nodes;
	size_t		next_to_fix;
	char		*nodes_array;
	size_t		limite;
	t_direction	limite_direction;
}		t_tools;

/*			init.c					*/
t_bool	initialisation(char **args, t_tools *tools);

/*			input_check.c			*/
t_bool	input_check(t_stack *a, char **args);

/*			limite.c				*/
void	find_index_limit(t_stack *stack, t_tools *tools, size_t nb_nodes);
size_t	calculate_nodes_to_push(t_tools *tools);
t_bool	has_nodes_under_limite(t_stack *stack, t_tools *tools);
t_bool	has_nodes_over_limite(t_stack *stack, t_tools *tools);
t_bool	is_node_to_push(t_tools *tools, size_t index);

/*			atoi_error_check.c		*/
int		ft_atoi_with_error_check(const char *nptr, t_bool *error_flag);

/*			stacks.c				*/
t_node	*new_node(int nb);
t_bool	add_node_tail(t_stack *stack, t_node *new);
t_bool	is_full_sorted(t_stack *stack);
void	stack_clear(t_tools *tools);
void	update_tail(t_stack *stack);

/*			commands.c				*/
void	swap(t_stack *stack, t_output *output);
void	push(t_stack *stack_src, t_stack *stack_dst, t_output *output);
void	rotate(t_stack *stack, t_output *output);
void	reverse_rotate(t_stack *stack, t_output *output);
void	sort_five_and_push(t_stack *src, t_stack *dst, t_tools *tools);
void	do_rotation(t_stack *stack, t_tools *tools);

/*			up_to_fives_nodes		*/
void	three_nodes_resolver(t_stack *stack, t_output *output);
void	four_nodes_resolver(t_stack *src, t_stack *dst, t_output *output);
void	five_nodes_resolver(t_stack *src, t_stack *dst, t_output *output);

/*			resolver.c				*/
void	resolver(t_tools *tools);
void	keep_half(t_tools *tools);

/*			up_to_five_nodes.c		*/
void	up_to_five_nodes(t_stack *src, t_stack *dst, t_output *output);

/*			nodes_fixing.c			*/
void	a_stack_process(t_tools *tools);
t_bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, t_tools *tools);
int	found_closest_nodes(t_stack *src, size_t next_to_fix);
t_bool	fixe_firsts_nodes(t_tools *tools);

/*			output.c	1 & 2		*/
void	print_to_buff(char *command, t_output *output);
void	print_remaining(t_output *output);
void	output_optimisation(t_output *output);

/*			utils.c					*/
void	push_nodes(t_stack *src, t_stack *dst, size_t index, t_output *output);
size_t	find_index(t_stack *stack, size_t to_find);
size_t	ft_abs(int	nb);

#endif