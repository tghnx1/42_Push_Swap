/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:44:33 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/07 18:19:23 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//put the last node to the top

void	rra(t_node ***a)
{
	t_node	*head;
	t_node	*current;

	if (!**a || !((**a)->next))
		return ;
	head = (**a);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = head;
	head->prev = current;
	**a = current;
}

void	rrb(t_node ***b)
{
	t_node	*head;
	t_node	*current;

	if (!**b || !((**b)->next))
		return ;
	head = (**b);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = head;
	head->prev = current;
	**b = current;
}

void	rrr(t_node ***a, t_node ***b)
{
	rra(a);
	rrb(b);
}
