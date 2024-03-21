/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_target_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:20:39 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/29 19:52:39 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb_target_node(t_node **a, t_node **b)
{
	int	both_up_down;

	both_up_down = 0;
	set_min_max(b);
	set_a_target_nodes(a, b);
	index_set(a, b);
	push_cost(a, b);
	set_the_cheapest(a);
	up_the_cheapest_a(a, b, both_up_down);
	print_pb(a, b);
}

void	pa_target_node(t_node **a, t_node **b)
{
	int	both_up_down;

	both_up_down = 0;
	set_min_max(a);
	set_b_target_nodes(a, b);
	index_set(a, b);
	push_cost(b, a);
	set_the_cheapest(b);
	up_the_cheapest_b(a, b, both_up_down);
	print_pa(a, b);
}
