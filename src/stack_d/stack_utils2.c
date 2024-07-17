/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:46:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/17 20:47:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_node *current;

	if (a)
	{
		ft_printf("Pila a: ");
		current = a->head;
		while (current != NULL)
		{
			ft_printf("[ %d ] ", current->num);
			current = current->next;
		}
	}
	ft_printf("\n");
	current = NULL;
	if (b)
	{
		ft_printf("Pila b: ");
		current = b->head;
		while (current != NULL)
		{
			ft_printf("[ %d ] ", current->num);
			current = current->next;
		}
	}
	ft_printf("\n\n");
}