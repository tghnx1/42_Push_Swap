/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:29:50 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/08 16:45:27 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_or_three_nodes_check(t_node **a, int num)
{
	if (already_sorted(a))
		return (0);
	if (num == 2 || num == 3)
		return (algoritm_three_nodes(a));
	return (1);
}
