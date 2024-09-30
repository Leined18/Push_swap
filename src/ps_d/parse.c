/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 09:56:52 by danpalac          #+#    #+#             */
/*   Updated: 2024/09/30 20:02:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_numbers(int count, int *j, char **s_numbers, int *numbers)
{
	int	k;

	k = 0;
	while (s_numbers[k])
	{
		if (count <= 1)
			ft_error("Error\n", 1);
		if (*j >= count)
		{
			free_2d(s_numbers);
			free(numbers);
			ft_error("Error\n", 1);
		}
		numbers[(*j)++] = ft_atoi(s_numbers[k++]);
	}
}

int	*parse(int argc, char **argv, int count)
{
	char	**s_numbers;
	int		*numbers;
	int		i;
	int		j;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
			ft_error("", 1);
		check_range(s_numbers, numbers);
		process_numbers(count, &j, s_numbers, numbers);
		free_2d(s_numbers);
	}
	return (numbers);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_rot_sort(t_stack *stack, int min_s_index)
{
	int	a;
	int	b;
	int	c;

	(void)min_s_index;
	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}
