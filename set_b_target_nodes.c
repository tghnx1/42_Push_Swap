/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b_target_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:45 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/28 17:21:26 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_b_target_nodes(t_node **a, t_node **b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_b)
	{
		set_closest_max_number(current_b, a);
		if (current_b ->target_node ->dif == LONG_MAX)
			set_min_node(current_b, a);
		current_b = current_b ->next;
	}
}

void	set_min_node(t_node *current_b, t_node	**a)
{
	t_node	*current_a;

	current_a = *a;
	while (current_a)
	{
		if (current_a -> min)
			current_b ->target_node = current_a;
		current_a = current_a -> next;
	}
}
