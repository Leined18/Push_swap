/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:03:17 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/19 12:34:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int i;

	i = TRUE;
	if (is_sorted(a))
	{
		free_stacks(a, b);
		free(num);
		exit(1);
	}
	else if (length == 2)
		swap(a, 'a', i);
	else if (length == 3)
		simple_sort(a, length);

	print_stack(a, b);
}