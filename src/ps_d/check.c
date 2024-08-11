/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:05:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/08/11 23:11:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(int argc, char **argv)
{
	int		i;
	char	*arg;
	char	*token;
	long	num;
	t_bool	seen[200001] = {FALSE};

	i = 0;
	while (++i < argc)
	{
		arg = argv[i];
		token = ft_strtok(arg, " ");
		while (token != NULL)
		{
			num = ft_atol(token);
			if (*token != '\0' && num == 0)
				ft_error("Error\n", 1);
			if (num < 0)
				num += 10000;
			if (seen[num] == TRUE)
				ft_error("Error\n", 1);
			seen[num] = TRUE;
			token = ft_strtok(NULL, " ");
		}
	}
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

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' || argv[i][j
					+ 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_range(t_stack *a, int *numbers)
{
	t_node	*c;

	c = a->head;
	while (c)
	{
		if (ft_atoll(ft_itoa(c->data)) > INT_MAX
			|| ft_atoll(ft_itoa(c->data)) < INT_MIN || ft_nbrlen(c->data) > 11)
		{
			free(numbers);
			ft_error("Error\n", 1);
		}
		c = c->next;
	}
}
