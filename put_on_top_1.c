/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_on_top_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:52:09 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/29 19:52:26 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	b_on_top(t_node **b, t_node *cheapest_b, int median)
{
	t_node	*current;
	int		i;
	int		j;
	int		last_index;

	last_index = last_node_index(b);
	current = cheapest_b;
	i = current->index;
	if (i < median)
	{
		while (i--)
			print_rb(b);
	}
	else
	{
		j = 0;
		while (j++ < last_index - i + 1)
			print_rrb(b);
	}
}

void	a_on_top(t_node **a, t_node *cheapest_a, int median)
{
	t_node	*current;
	int		i;
	int		j;
	int		last_index;

	last_index = last_node_index(a);
	current = cheapest_a;
	i = current->index;
	if (i < median)
	{
		while (i--)
			print_ra(a);
	}
	else
	{
		j = 0;
		while (j++ < last_index - i + 1)
			print_rra(a);
	}
}

void	both_up_on_top(t_node **a, t_node **b, t_node *cheapest)
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
			print_rb(b);
	}
	if (!(cheapest->target_node->prev))
	{
		while (cheapest->prev)
			print_ra(a);
	}
}

void	both_down_on_top(t_node **a, t_node **b, t_node *cheapest)
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
			print_rrb(b);
	}
	if (!(cheapest->target_node->prev))
	{
		while (cheapest->prev)
			print_rra(a);
	}
}

void	both_on_top(t_node **a, t_node **b, t_node *cheapest)
{
	int	median_a;
	int	median_b;

	median_a = median_count(*a);
	median_b = median_count(*b);
	if ((median_a + median_b >= cheapest->index
			+ cheapest->target_node->index))
		both_up_on_top(a, b, cheapest);
	else
		both_down_on_top(a, b, cheapest);
}
