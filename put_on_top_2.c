/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_top_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:52:09 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/29 19:04:03 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	both_up_on_top_2(t_node **a, t_node **b, t_node *cheapest)
{
	int	median_a;
	int	median_b;

	median_a = median_count(*a);
	median_b = median_count(*b);
	while (cheapest->prev && cheapest->target_node->prev)
		print_rr(a, b);
	if (!(cheapest->prev))
	{
		while (cheapest->target_node->prev)
			print_ra(a);
	}
	if (!(cheapest->target_node->prev))
	{
		while (cheapest->prev)
			print_rb(b);
	}
}

void	both_down_on_top_2(t_node **a, t_node **b, t_node *cheapest)
{
	int	median_a;
	int	median_b;

	median_a = median_count(*a);
	median_b = median_count(*b);
	while (cheapest->prev && cheapest->target_node->prev)
		print_rrr(a, b);
	if (!(cheapest->prev))
	{
		while (cheapest->target_node->prev)
			print_rra(a);
	}
	if (!(cheapest->target_node->prev))
	{
		while (cheapest->prev)
			print_rrb(b);
	}
}

void	both_on_top_2(t_node **a, t_node **b, t_node *cheapest)
{
	int	median_a;
	int	median_b;

	median_a = median_count(*a);
	median_b = median_count(*b);
	if ((median_a + median_b >= cheapest->index
			+ cheapest->target_node->index))
		both_up_on_top_2(a, b, cheapest);
	else
		both_down_on_top_2(a, b, cheapest);
}
