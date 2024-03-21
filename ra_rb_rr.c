/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:47:55 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/12 16:32:28 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_node ***a)
{
	t_node	*head;
	t_node	*current;

	if (!**a || !((**a)->next))
		return ;
	head = (**a);
	**a = (**a)->next;
	(**a)->prev = NULL;
	current = head;
	while (current->next != NULL)
		current = current->next;
	head->next = NULL;
	head->prev = current;
	current->next = head;
}

void	rb(t_node ***b)
{
	t_node	*head;
	t_node	*current;

	if (!**b || !((**b)->next))
		return ;
	head = (**b);
	**b = (**b)->next;
	(**b)->prev = NULL;
	current = head;
	while (current->next != NULL)
		current = current->next;
	head->next = NULL;
	head->prev = current;
	current->next = head;
}

void	rr(t_node ***a, t_node ***b)
{
	ra(a);
	rb(b);
}
