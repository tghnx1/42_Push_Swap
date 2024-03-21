/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:40:43 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/29 19:06:16 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

//# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <limits.h>

typedef struct nodes
{
	struct nodes	*prev;
	int				number;
	int				max;
	int				min;
	int				index;
	int				push_cost;
	int				cheapest;
	long			dif;
	struct nodes	*target_node;
	struct nodes	*next;
}	t_node;

char	*put_in_arr(int argc, char **argv);

t_node	*stack_init(char **params, int num);

int		free_params(char **params);

void	print_list(t_node *head);

void	*free_list(t_node *head, int num);

int		algoritm(t_node **a, t_node **b, int num);

void	sa(t_node ***a);

void	sb(t_node ***b);

void	ss(t_node ***a, t_node ***b);

void	pb(t_node ***a, t_node ***b);

void	pa(t_node ***a, t_node ***b);

void	ra(t_node ***a);

void	rb(t_node ***b);

void	rr(t_node ***a, t_node ***b);

void	rra(t_node ***a);

void	rrb(t_node ***b);

void	rrr(t_node ***a, t_node ***b);

void	print_sa(t_node	**a);

void	print_pa(t_node	**a, t_node **b);

void	print_ra(t_node	**a);

void	print_rra(t_node	**a);

void	print_sb(t_node	**b);

void	print_pb(t_node **a, t_node	**b);

void	print_rb(t_node	**b);

void	print_rrb(t_node **b);

void	print_ss(t_node	**a, t_node **b);

void	print_rr(t_node	**a, t_node **b);

void	print_rrr(t_node	**a, t_node **b);

void	set_min(t_node **head);

void	set_max(t_node **head);

void	set_min_max(t_node **head);

void	set_a_target_nodes(t_node **a, t_node **b);

void	set_closest_min_number(t_node *current_a, t_node **b);

void	index_set(t_node	**a, t_node	**b);

int		count_nodes(t_node	**head);

int		median_count(t_node	*head);

void	current_cost_count(t_node	**a, t_node	**b,
			int med_common, int median_a);

void	set_the_cheapest(t_node	**head);

void	push_the_cheapest(t_node	**a, t_node	**b);

void	push_cost(t_node	**a, t_node	**b);

int		last_node_index(t_node	**head);

void	index_set(t_node	**a, t_node	**b);

void	cost_count_not_top(t_node *current, int med_common,
			int last_node_index_a, int last_node_index_b);

void	up_the_cheapest_a(t_node	**a, t_node	**b, int both_up_down);

void	up_the_cheapest_b(t_node	**b, t_node	**a, int both_up_down);

int		cost_each(t_node	**head, int index, int median);

void	a_on_top(t_node **b, t_node *cheapest_b, int median);

void	b_on_top(t_node **a, t_node *cheapest_a, int median);

void	both_up_on_top(t_node **a, t_node **b, t_node *cheapest);

void	both_down_on_top(t_node **a, t_node **b, t_node *cheapest);

void	both_on_top(t_node **a, t_node **b, t_node *cheapest);

void	set_closest_max_number(t_node *current_b, t_node **a);

void	set_min_node(t_node *current_a, t_node	**b);

void	set_b_target_nodes(t_node **a, t_node **b);

void	put_min_on_top(t_node **a, t_node **b);

void	pb_target_node(t_node **a, t_node **b);

void	pa_target_node(t_node **a, t_node **b);

int		sort_or_three_nodes_check(t_node **a, int num);

int		already_sorted(t_node **a);

int		algoritm_three_nodes(t_node **a);

void	nodes_init(char **params, t_node	**node, int num);

void	both_up_on_top_2(t_node **a, t_node **b, t_node *cheapest);

void	both_down_on_top_2(t_node **a, t_node **b, t_node *cheapest);

void	both_on_top_2(t_node **a, t_node **b, t_node *cheapest);
#endif
