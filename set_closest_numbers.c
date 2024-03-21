/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_closest_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:27 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/23 16:46:01 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_closest_min_number(t_node *current_a, t_node **b)
{
	t_node	*current_b;

	current_a ->target_node = *b;
	current_b = *b;
	while (current_b)
	{
		current_b->dif = current_a ->number - current_b -> number;
		if (current_b->dif < 0)
		{
			current_b->dif = LONG_MAX;
		}
		if (current_b->prev)
		{
			if ((current_b -> dif < current_a -> target_node -> dif))
			{
				current_a ->target_node = current_b;
			}
		}
		current_b = current_b -> next;
	}
}

void	set_closest_max_number(t_node *current_b, t_node **a)
{
	t_node	*current_a;

	current_b ->target_node = *a;
	current_a = *a;
	while (current_a)
	{
		current_a->dif = current_a ->number - current_b -> number;
		if (current_a->dif < 0)
		{
			current_a->dif = LONG_MAX;
		}
		if (current_a->prev)
		{
			if ((current_a -> dif < current_b -> target_node -> dif))
			{
				current_b ->target_node = current_a;
			}
		}
		current_a = current_a -> next;
	}
}
