/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:31 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/21 19:23:05 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_sb(t_node	**b)
{
	sb(&b);
	write(1, "sb\n", 3);
}

void	print_pb(t_node **a, t_node	**b)
{
	pb(&a, &b);
	write(1, "pb\n", 3);
}

void	print_rb(t_node	**b)
{
	rb(&b);
	write(1, "rb\n", 3);
}

void	print_rrb(t_node **b)
{
	rrb(&b);
	write(1, "rrb\n", 4);
}
