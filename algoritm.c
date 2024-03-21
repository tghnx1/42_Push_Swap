/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:20 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/08 16:41:10 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	already_sorted(t_node **a)
{
	t_node	*current;
	int		i;

	i = 1;
	current = *a;
	while (current->next)
	{
		if (current->number > current->next->number)
		{
			i = 0;
			break ;
		}
		else
			current = current->next;
	}
	return (i);
}

int	algoritm_three_nodes(t_node **a)
{
	t_node	*current;

	current = *a;
	index_set(a, a);
	set_min_max(a);
	if (current->next->max)
		print_rra(a);
	else if (current->max)
		print_ra(a);
	current = *a;
	if (current->number > current->next->number)
		print_sa(a);
	return (0);
}

void	set_max_node(t_node *current_a, t_node	**b)
{
	t_node	*current_b;

	current_b = *b;
	while (current_b)
	{
		if (current_b -> max)
			current_a ->target_node = current_b;
		current_b = current_b -> next;
	}
}

void	set_a_target_nodes(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a)
	{
		set_closest_min_number(current_a, b);
		if (current_a ->target_node ->dif == LONG_MAX)
			set_max_node(current_a, b);
		current_a = current_a ->next;
	}
}

int	algoritm(t_node **a, t_node **b, int num)
{
	if (!(sort_or_three_nodes_check(a, num)))
		return (0);
	while (count_nodes(a) > 3)
	{
		if (count_nodes(a) == 4)
			print_pb(a, b);
		else
		{
			print_pb(a, b);
			print_pb(a, b);
		}
		if (count_nodes(a) == 3)
			break ;
		pb_target_node(a, b);
	}
	algoritm_three_nodes(a);
	while (count_nodes(b))
		pa_target_node(a, b);
	set_min_max(a);
	put_min_on_top(a, b);
	return (0);
}
