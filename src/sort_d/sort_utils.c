/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:53:17 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/19 12:09:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_r(t_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

int	get_min_index(t_stack *stack)
{
	t_node *current;
	int min_index;

	current = stack->head;
	min_index = current->index;
	while (current->next)
	{
		current = current->next;
		if (current->index < min_index)
			min_index = current->index;
	}
	return (min_index);
}