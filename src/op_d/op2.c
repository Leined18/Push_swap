/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:57:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/17 21:09:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	t_node	*first;

	if (stack2->size == 0)
		return ;
	first = stack2->head;
	stack2->head = first->next;
	if (stack2->head != NULL)
		stack2->head->prev = NULL;
	else
		stack2->tail = NULL;
	first->next = stack1->head;
	if (stack1->head != NULL)
		stack1->head->prev = first;
	else
		stack1->tail = first;
	stack1->head = first;
	stack1->size++;
	stack2->size--;
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 'a', FALSE);
	rotate(stack_b, 'b', FALSE);
	write(1, "rr\n", 3);
}

void	swap_both(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1, 'a', FALSE);
	rotate(stack2, 'b', FALSE);
	write(1, "ss\n", 3);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, 'a', FALSE);
	reverse_rotate(stack_b, 'b', FALSE);
	write(1, "rrr\n", 3);
}
