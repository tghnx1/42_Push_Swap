/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:47:47 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/28 17:47:36 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_nodes(t_node	**head)
{
	t_node	*current;
	int		num;

	num = 0;
	current = *head;
	while (current)
	{
		current = current->next;
		num++;
	}
	return (num);
}

void	index_set(t_node	**a, t_node	**b)
{
	int		i;
	t_node	*current;

	i = 0;
	current = *a;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	i = 0;
	current = *b;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}

void	cost_count_not_top(t_node *current, int med_common,
			int last_node_index_a, int last_node_index_b)
{
	int	cost_a;
	int	cost_b;
	int	ind_common;

	ind_common = current->index + current->target_node->index;
	if (ind_common >= med_common)
	{
		cost_a = last_node_index_a - current->index + 1;
		cost_b = last_node_index_b - current->target_node->index + 1;
	}
	else
	{
		cost_a = current->index;
		cost_b = current->target_node->index;
	}
	if (cost_a > cost_b)
		current->push_cost = cost_a;
	else
		current->push_cost = cost_b;
}

void	put_min_on_top(t_node **a, t_node **b)
{
	t_node	*current;
	int		i;
	int		j;
	int		median;
	int		last_index;

	index_set(a, b);
	last_index = last_node_index(a);
	median = median_count(*a);
	current = *a;
	j = 0;
	while (!(current->min))
		current = current -> next;
	i = current->index;
	if (i <= median)
	{
		while (i--)
			print_ra(a);
	}
	else
	{
		while (j++ < last_index - i + 1)
			print_rra(a);
	}
}
