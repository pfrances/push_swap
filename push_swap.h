/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/09 02:01:54 by pfrances         ###   ########.fr       */
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
	size_t		*limites_array;
	size_t		limite_value_a;
	size_t		limite_value_b;
	t_direction	limite_direction;
}		t_tools;


/*			push_swap.c				*/
void	print_lists(t_stack *a, t_stack *b);

/*			init.c					*/
t_bool	stack_init(t_tools *tools, char **args);
t_bool	output_init(t_tools *tools);

/*			limite.c				*/
t_bool	set_limites_array(t_tools *tools);

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
void	sort_five_and_push(t_stack *src, t_stack *dst, t_output *output);
void	do_rotation(t_stack *stack, t_tools *tools);

/*			resolver.c				*/
void	resolver(t_tools *tools);
void	keep_half(t_tools *tools);
size_t	find_index_limit(t_stack *stack, t_tools *tools);

/*			up_to_five_nodes.c		*/
void	up_to_five_nodes(t_stack *src, t_stack *dst, t_output *output);

/*			nodes_fixing.c			*/
void	fixe_sorted_node(t_tools *tools);
t_bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, t_tools *tools);
t_bool	fixe_firsts_nodes(t_tools *tools);

/*			output.c				*/
void	print_to_buff(char *command, t_output *output);
void	print_remaining(t_output *output);

#endif