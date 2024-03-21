/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:36:30 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/28 17:21:12 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb(t_node ***a, t_node ***b)
{
	t_node	*b_first;

	if (!(**a))
		return ;
	b_first = **a;
	if ((**a)->next)
	{
		(**a) = (**a)->next;
		(**a)->prev = NULL;
	}
	else
		(**a) = NULL;
	b_first->prev = NULL;
	if (!(**b))
		b_first->next = NULL;
	else
	{
		b_first->next = (**b);
		(**b)->prev = b_first;
	}
	**b = b_first;
}

void	pa(t_node ***a, t_node ***b)
{
	t_node	*a_first;

	if (!(**b))
		return ;
	a_first = **b;
	if ((**b)->next)
		(**b) = (**b)->next;
	else
		(**b) = NULL;
	a_first->prev = NULL;
	if (!(**a))
		a_first->next = NULL;
	else
	{
		a_first->next = (**a);
		(**a)->prev = a_first;
	}
	**a = a_first;
}
