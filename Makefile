# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 17:52:33 by mkokorev          #+#    #+#              #
#    Updated: 2024/03/08 16:43:04 by mkokorev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTFDIR = ./printf
PRINTF_LIB_PATH = $(PRINTFDIR)/libftprintf.a

SRCS = 	algoritm.c \
		check.c \
		main.c \
		moreutils.c \
		nodes_init.c \
		pa_pb.c \
		print_commands_a.c \
		print_commands_a_b.c \
		print_commands_b.c \
		push_cost_count.c \
		pushswap_utils.c \
		push_target_node.c \
		push_the_cheapest.c \
		put_on_top_1.c \
		put_on_top_2.c \
		ra_rb_rr.c \
		rra_rrb_rrr.c \
		sa_sb_ss.c \
		set_b_target_nodes.c \
		set_closest_numbers.c \
		set_min_max_in_list.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeprintf:
	@make -C $(PRINTFDIR) || exit 1
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): makeprintf $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(PRINTF_LIB_PATH)

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(PRINTFDIR) && make fclean

re: fclean all
