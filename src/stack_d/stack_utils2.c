/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:46:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/19 11:23:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	del_stack(t_stack *stack)
{
	t_node	*top;
	int		data;

	if (!stack->head)
		exit(1);
	top = stack->head;
	data = top->data;
	stack->head = top->next;
	free(top);
	top = NULL;
	stack->size--;
	return (data);
}

void	print_stack(t_stack *a, t_stack *b)
{
	t_node *current;

	if (a)
	{
		ft_printf("Pila a: ");
		current = a->head;
		while (current != NULL)
		{
			ft_printf("[ %d ] ", current->data);
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
			ft_printf("[ %d ] ", current->data);
			current = current->next;
		}
	}
	ft_printf("\n\n");
}