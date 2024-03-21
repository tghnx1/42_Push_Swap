/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:31 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/08 19:34:17 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_ss(t_node	**a, t_node **b)
{
	ss(&a, &b);
	write(1, "ss\n", 3);
}

void	print_rr(t_node	**a, t_node **b)
{
	rr(&a, &b);
	write(1, "rr\n", 3);
}

void	print_rrr(t_node	**a, t_node **b)
{
	rrr(&a, &b);
	write(1, "rrr\n", 4);
}
