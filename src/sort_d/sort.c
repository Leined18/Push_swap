/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:03:17 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/17 21:05:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b, int length)
{
	int i;

	i = TRUE;
	if (is_sorted(a))
	{
		free_stacks(a, b, length);
		exit(1);
	}
	else if (length == 2)
		swap(a, 'a', i);

	print_stack(a, b);
}