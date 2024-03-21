/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:19 by mkokorev          #+#    #+#             */
/*   Updated: 2024/02/28 19:06:29 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	nodes_init(char **params, t_node	**node, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		node[i] = (t_node *)(malloc(sizeof(t_node)));
		if (!(node[i]))
			return ;
		if (i == 0)
			node[i]->prev = NULL;
		else
		{
			node[i]->prev = node[i - 1];
			node[i - 1]->next = node[i];
		}
		node[i]->next = NULL;
		node[i]->number = ft_atoi(params[i]);
		i++;
	}
}
