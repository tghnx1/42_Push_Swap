/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:37:24 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/08 16:41:22 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*put_in_arr(int argc, char **argv)
{
	char	*arr;
	char	*temp;
	int		i;

	i = 2;
	if (argc == 1)
	{
		return (NULL);
	}
	arr = ft_strdup(argv[1]);
	while (i < argc)
	{
		temp = arr;
		arr = ft_strjoin(arr, " ");
		free(temp);
		temp = arr;
		arr = ft_strjoin(arr, argv[i]);
		if (!arr)
			return (0);
		free(temp);
		i++;
	}
	return (arr);
}

t_node	*stack_init(char **params, int num)
{
	t_node	**node;
	t_node	*head;
	int		i;

	i = 0;
	node = (t_node **)malloc(num * sizeof(t_node *));
	if (!(node))
		return (NULL);
	nodes_init(params, node, num);
	head = node[0];
	free(node);
	node = NULL;
	return (head);
}

void	print_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current)
	{
		ft_printf("%d;	", current->number);
		ft_printf("index: %d;	", current->index);
		ft_printf("push_cost: %d;	", current->push_cost);
		ft_printf("the cheapest: %d;	", current->cheapest);
		ft_printf("min: %d;	", current->min);
		ft_printf("max: %d;	", current->max);
		if (current->target_node)
			ft_printf("target node: %d\n", current->target_node->number);
		else
			write (1, "\n", 1);
		current = current->next;
	}
}

void	*free_list(t_node *head, int num)
{
	int		i;
	t_node	*current;
	t_node	*temp;

	if (!head)
		return (NULL);
	i = 0;
	current = head;
	while (i < num)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
		i++;
	}
	return (NULL);
}

int	last_node_index(t_node	**head)
{
	t_node	*last;

	last = *head;
	while (last->next)
		last = last->next;
	return (last->index);
}
