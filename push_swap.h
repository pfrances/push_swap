/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:20:46 by pfrances          #+#    #+#             */
/*   Updated: 2022/09/19 18:27:48 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define STACK_A 0
# define STACK_B 1
# define BUFFER_SIZE 1024
# define DEL "pa\npb\n pb\npa\n \nra\nrra rra\nra\n \nrb\nrrb rrb\nrb\n sa\nsa\n sb\nsb\n"
# define FROM "\nra\nrb \nrb\nra rra\nrrb rrb\nrra sa\nsb sb\nsa \nra\npb\nrra \nrb\npa\nrrb"
# define TO "\nrrXXX \nrrXXX rrrXXXX rrrXXXX ssXXX ssXXX \nsa\npbXXXX \nsb\npaXXXX"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

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
	size_t		limite_low;
	size_t		limite_high;
}		t_tools;

/*			init.c					*/
bool	initialisation(char **args, t_tools *tools);
/*			do_parsing.c			*/
bool	do_parsing(t_stack *a, char **args);
/*			atoi_error_check.c		*/
int		ft_atoi_with_error_check(const char *nptr, bool *error_flag);

/*			stacks.c				*/
t_node	*new_node(int nb);
bool	add_node_tail(t_stack *stack, t_node *new);
bool	is_full_sorted(t_stack *stack);
void	stack_clear(t_tools *tools);
void	update_tail(t_stack *stack);

/*			commands.c				*/
size_t	swap(t_stack *stack, t_output *output);
size_t	push(t_stack *stack_src, t_stack *stack_dst, t_output *output);
size_t	rotate(t_stack *stack, t_output *output);
size_t	reverse_rotate(t_stack *stack, t_output *output);

/*			up_to_fives_nodes		*/
void	three_nodes_resolver(t_stack *stack, t_output *output);
void	four_nodes_resolver(t_stack *src, t_stack *dst, t_output *output);
void	five_nodes_resolver(t_stack *src, t_stack *dst, t_output *output);
void	up_to_five_nodes(t_stack *src, t_stack *dst, t_output *output);
void	sort_five_and_push(t_stack *src, t_stack *dst, t_tools *tools);

/*			resolver.c				*/
void	resolver(t_tools *tools);
/*			stack_a_process.c		*/
void	stack_a_process(t_tools *tools);
/*			stack_b_process.c		*/
void	stack_b_process(t_tools *tools);

/*			limite.c				*/
void	set_index_limit(t_stack *stack, t_tools *tools, size_t nb_nodes);
bool	has_nodes_under_limite(t_stack *stack, t_tools *tools);
bool	has_nodes_over_limite(t_stack *stack, t_tools *tools);

/*			output1.c				*/
void	print_to_buff(char *command, t_output *output);
void	print_remaining(t_output *output);
/*			output2.c				*/
void	output_optimisation(t_output *output);

/*			utils1.c					*/
size_t	find_index(t_stack *stack, size_t to_find);
size_t	ft_abs(int nb);
/*			utils2.c				*/
bool	find_nodes_easy_to_fixe(t_stack *src, t_stack *dst, t_tools *tools);
void	push_nodes(t_stack *src, t_stack *dst, size_t index, t_output *output);
/*			utils3.c				*/
size_t	calculate_nodes_to_push(t_tools *tools);

#endif