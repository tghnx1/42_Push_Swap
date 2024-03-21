/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:54:15 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/28 17:21:20 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	median_count(t_node	*head)
{
	int		median;
	t_node	*current;

	current = head;
	while (current)
	{
		if (count_nodes(&head) % 2 == 0)
			median = count_nodes(&head) / 2;
		else
			median = (count_nodes(&head) + 1) / 2;
		current = current->next;
	}
	return (median);
}

int	cost_each(t_node	**head, int index, int median)
{
	int		cost;
	t_node	*current;
	t_node	*last;

	current = *head;
	last = *head;
	while (last->next)
		last = last->next;
	if (index >= median)
		cost = last->index - current->index + 1;
	else
		cost = current->index;
	return (cost);
}

void	push_cost(t_node	**a, t_node	**b)
{
	t_node	*current;
	int		med_common;
	int		median_a;
	int		median_b;

	median_a = median_count(*a);
	median_b = median_count(*b);
	med_common = median_count(*a) + median_count(*b);
	current = *a;
	while (current)
	{
		current_cost_count(&current, b, med_common, median_a);
		current = current->next;
	}
	current = *b;
	while (current)
	{
		current->push_cost = 0;
		current->cheapest = 0;
		current->target_node = NULL;
		current = current->next;
	}
}

void	current_cost_count(t_node	**a, t_node	**b,
			int med_common, int median_a)
{
	int		ind_common;
	int		median_b;
	int		last_node_index_a;
	int		last_node_index_b;
	t_node	*current;

	current = *a;
	median_b = med_common - median_a;
	ind_common = (*a)->index + (*a)->target_node->index;
	last_node_index_a = last_node_index(a);
	last_node_index_b = last_node_index(b);
	if (!((*a)->prev))
		(*a)->push_cost = cost_each(&current->target_node,
				(*a)->target_node->index, median_b);
	if (!((*a)->target_node->prev))
		(*a)->push_cost = cost_each(a, (*a)->index, median_a);
	else
		cost_count_not_top(*a, med_common, last_node_index_a,
			last_node_index_b);
	if (((cost_each(&current->target_node, (*a)->target_node->index, median_b)
				+ cost_each(a, (*a)->index, median_a))) < ((*a)->push_cost))
		(*a)->push_cost = cost_each(&current->target_node,
				(*a)->target_node->index, median_b)
			+ cost_each(a, (*a)->index, median_a);
}
