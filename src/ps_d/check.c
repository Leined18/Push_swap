/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:05:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/19 10:56:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check(int argc, char **argv)
{
	int		i;
	char	*arg;
	char	*token;
	long	num;
	t_bool	seen[20001];

	i = 0;
	*seen = false;
	while (++i < argc)
	{
		arg = argv[i];
		token = ft_strtok(arg, " ");
		while (token != NULL)
		{
			num = ft_atol(token);
			if (*token != '\0' && num == 0)
				ft_error("", 2);
			if (num < 0)
				num += 10000;
			if (seen[num])
				ft_error("", 2);
			seen[num] = true;
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
