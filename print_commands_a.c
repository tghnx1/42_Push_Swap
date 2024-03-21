/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:31 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/08 19:34:09 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_sa(t_node	**a)
{
	sa(&a);
	write(1, "sa\n", 3);
}

void	print_pa(t_node	**a, t_node **b)
{
	pa(&a, &b);
	write(1, "pa\n", 3);
}

void	print_ra(t_node	**a)
{
	ra(&a);
	write(1, "ra\n", 3);
}

void	print_rra(t_node	**a)
{
	rra(&a);
	write(1, "rra\n", 4);
}
