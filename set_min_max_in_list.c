/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_max_in_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:59:30 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/28 18:50:56 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_min(t_node **head)
{
	t_node	*current;
	t_node	*compare;

	current = *head;
	compare = *head;
	while (current -> next)
	{
		compare->min = 1;
		if (!(compare -> next))
			break ;
		if (compare->number > current->next->number)
		{
			compare -> min = 0;
			if (current-> next)
				compare = current -> next;
		}
		else
			current = current -> next;
	}
}

void	set_max(t_node **head)
{
	t_node	*current;
	t_node	*compare;

	current = *head;
	compare = *head;
	current = *head;
	while (current -> next)
	{
		compare->max = 1;
		if (!(compare -> next))
			break ;
		if (compare->number < current->next->number)
		{
			compare -> max = 0;
			if (current-> next)
				compare = current -> next;
		}
		else
			current = current -> next;
	}
}

void	set_min_max(t_node **head)
{
	t_node	*current;

	current = *head;
	while (current)
	{
		current->min = 0;
		current->max = 0;
		current = current-> next;
	}
	set_min(head);
	set_max(head);
}
