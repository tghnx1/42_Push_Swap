/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_the_cheapest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:31:46 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/29 19:52:31 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_the_cheapest(t_node	**head)
{
	t_node	*current;
	t_node	*compare;

	current = *head;
	compare = *head;
	if (!(*head)->next)
	{
		(*head)->cheapest = 1;
		return ;
	}
	current = *head;
	while (current -> next)
	{
		compare->cheapest = 1;
		if (!(compare -> next))
			break ;
		if (compare->push_cost > current->next->push_cost)
		{
			compare -> cheapest = 0;
			if (current-> next)
				compare = current -> next;
		}
		else
			current = current -> next;
	}
}

void	up_the_cheapest_a(t_node	**a, t_node	**b, int both_up_down)
{
	int		median_a;
	int		median_b;
	t_node	*cheapest;

	cheapest = *a;
	while (!(cheapest->cheapest))
		cheapest = cheapest->next;
	median_a = median_count(*a);
	median_b = median_count(*b);
	if ((cost_each(&cheapest->target_node, (cheapest)->target_node->index,
				median_b) + cost_each(&cheapest, cheapest->index,
				median_a)) > cheapest->push_cost)
		both_up_down = 1;
	if (!(cheapest->prev))
		b_on_top(b, cheapest->target_node, median_b);
	else if (!(cheapest->target_node->prev))
		a_on_top(a, cheapest, median_a);
	else if (both_up_down)
		both_on_top(a, b, cheapest);
	else
	{
		b_on_top(b, cheapest->target_node, median_b);
		a_on_top(a, cheapest, median_a);
	}
}

void	up_the_cheapest_b(t_node	**a, t_node	**b, int both_up_down)
{
	int		median_a;
	int		median_b;
	t_node	*cheapest;

	cheapest = *b;
	while (!(cheapest->cheapest))
		cheapest = cheapest->next;
	median_b = median_count(*b);
	median_a = median_count(*a);
	if ((cost_each(&cheapest->target_node, (cheapest)->target_node->index,
				median_a) + cost_each(&cheapest, cheapest->index,
				median_b)) > cheapest->push_cost)
		both_up_down = 1;
	if (!(cheapest->prev))
		a_on_top(a, cheapest->target_node, median_a);
	else if (!(cheapest->target_node->prev))
		b_on_top(b, cheapest, median_b);
	else if (both_up_down)
		both_on_top_2(a, b, cheapest);
	else
	{
		a_on_top(a, cheapest->target_node, median_a);
		b_on_top(b, cheapest, median_b);
	}
}
