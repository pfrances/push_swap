# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 22:35:44 by pfrances          #+#    #+#              #
#    Updated: 2022/09/15 12:30:57 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	up_to_five_nodes/three_nodes.c		\
		up_to_five_nodes/four_nodes.c		\
		up_to_five_nodes/five_nodes.c		\
		up_to_five_nodes/up_to_five_nodes.c	\
		initialisation/atoi_error_check.c	\
		initialisation/init.c				\
		initialisation/input_check.c		\
		commands.c							\
		limite.c							\
		output1.c							\
		output2.c							\
		push_swap.c							\
		resolver.c							\
		stack_a_process.c					\
		stack_b_process.c					\
		stacks.c							\
		utils1.c							\
		utils2.c							\
		utils3.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CHECKER = checker

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

visu:$(NAME)
	cp $(NAME) push_swap_visualizer/$(NAME)
	./push_swap_visualizer/build/bin/visualizer

valgrind: $(NAME)
	ARG=$$(seq -1000 1000 | shuf | head -n 100); valgrind -s ./$(NAME) $$ARG

run: $(NAME)
	ARG=$$(seq -1000 1000 | shuf | head -n 100); echo $$ARG && ./$(NAME) $$ARG

test: test100

test5: $(NAME)
	ARG=$$(seq -1000 1000 | shuf | head -n 5); echo $$ARG && ./$(NAME) $$ARG | ./$(CHECKER) $$ARG && echo -n 'count : '&& ./$(NAME) $$ARG | wc -l

test100: $(NAME)
	ARG=$$(seq -1000 1000 | shuf | head -n 100); echo $$ARG && ./$(NAME) $$ARG | ./$(CHECKER) $$ARG && echo -n 'count : '&& ./$(NAME) $$ARG | wc -l

test500: $(NAME)
	ARG=$$(seq -1000 1000 | shuf | head -n 500); echo $$ARG && ./$(NAME) $$ARG | ./$(CHECKER) $$ARG && echo -n 'count : '&& ./$(NAME) $$ARG | wc -l

.PHONY: all clean fclean re visu valgrind run test5 test100 test100