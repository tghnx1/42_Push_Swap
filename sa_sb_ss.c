/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:41:44 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/08 13:23:15 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
#include "pushswap.h"

void	sa(t_node ***a)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!**a || !((**a)->next))
		return ;
	first_node = **a;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;
	if (first_node->next)
		first_node->next->prev = first_node;
	**a = second_node;
}

void	sb(t_node ***b)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!**b || !((**b)->next))
		return ;
	first_node = **b;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;
	if (first_node->next)
		first_node->next->prev = first_node;
	**b = second_node;
}

void	ss(t_node ***a, t_node ***b)
{
	sa(a);
	sb(b);
}
