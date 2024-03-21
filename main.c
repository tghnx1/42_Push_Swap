/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkokorev <mkokorev@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:34:53 by mkokorev          #+#    #+#             */
/*   Updated: 2024/03/01 13:38:28 by mkokorev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	param_handle(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!(arr[i] == '\t' || arr[i] == '\n' || arr[i] == ' '
				|| arr[i] == '-' || (arr[i] >= '0' && (arr[i] <= '9'))))
		{
			free(arr);
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	double_and_size_handle(char **params, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (params[i] || i < num - 1)
	{
		if (ft_atoi(params[i]) > INT_MAX || ft_atoi(params[i]) < INT_MIN)
		{
			write(1, "Error\n", 6);
			return (free_params(params));
		}
		while (j < num)
		{
			if (ft_atoi(params[i]) == ft_atoi(params[j++]))
			{
				write(1, "Error\n", 6);
				return (free_params(params));
			}
		}
		i++;
		j = i + 1;
	}
	return (1);
}

char	**separate(char *arr, int *num)
{
	char	**params;
	int		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '\n' || arr[i] == '\t')
			arr[i] = ' ';
		i++;
	}
	params = ft_split(arr, ' ');
	free(arr);
	i = 0;
	while (params[i] != NULL)
		i++;
	*num = i;
	return (params);
}

int	free_params(char **params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (params[i] != NULL)
		i++;
	while (j <= i)
	{
		free(params[j]);
		params[j] = NULL;
		j++;
	}
	free(params);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*arr;
	char	**params;
	int		num;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	num = 0;
	arr = put_in_arr(argc, argv);
	if ((arr == NULL) || (!param_handle(arr)))
		return (0);
	params = separate(arr, &num);
	if (!(double_and_size_handle(params, num)))
		return (0);
	a = stack_init(params, num);
	free_params(params);
	algoritm(&a, &b, num);
	free_list(a, num);
	return (0);
}
