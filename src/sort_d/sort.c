/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:03:17 by danpalac          #+#    #+#             */
/*   Updated: 2024/09/20 11:39:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index = get_min_index(stack_a);
		if (count_r(stack_a->head, min_index) <= n - min_index
			- count_r(stack_a->head, min_index))
			while (stack_a->head->index != min_index)
				rotate(stack_a, 'a', TRUE);
		else
			while (stack_a->head->index != min_index)
				reverse_rotate(stack_a, 'a', TRUE);
		if (is_sorted(stack_a) && stack_b->size == 0)
			return ;
		push(stack_b, stack_a, 'b', TRUE);
		length--;
	}
	simple_sort(stack_a, length);
	iter = 0;
	while (iter++ < n - 3)
		push(stack_a, stack_b, 'a', TRUE);
}

void	simple_sort(t_stack *stack, int length)
{
	int	min_s_index;
	int	r;

	if (is_sorted(stack))
		return ;
	min_s_index = get_min_index(stack);
	r = count_r(stack->head, min_s_index);
	if (is_rot_sort(stack, min_s_index))
	{
		if (r < length - r)
			rotate(stack, 'a', TRUE);
		else
			reverse_rotate(stack, 'a', TRUE);
	}
	else
	{
		swap(stack, 'a', TRUE);
		if (is_sorted(stack))
			return ;
		if (r < length - r)
			rotate(stack, 'a', TRUE);
		else
			reverse_rotate(stack, 'a', TRUE);
	}
}

void	sort(t_stack *a, t_stack *b, int *num, int length)
{
	int	i;

	i = TRUE;
	if (is_sorted(a))
	{
		free_stacks(a, b);
		free(num);
		ft_error("\033[0mError\n", 1);
	}
	else if (length == 2)
		swap(a, 'a', i);
	else if (length == 3)
		simple_sort(a, length);
	else if (length <= 7)
		insert_sort(a, b, length);
	else if (length > 7)
	{
		k_sort1(a, b, length);
		k_sort2(a, b, length);
	}
	else
		ft_error("\033[0m", 1);
}
