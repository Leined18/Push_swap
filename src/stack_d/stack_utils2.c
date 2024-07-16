/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:52:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/16 12:49:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_zero(t_stack **stack, int argc)
{
	int i;

	i = 1;
	*stack = NULL;
	while (i < argc)
	{
		ft_add_back(stack, ft_new(0));
		i++;
	}
}