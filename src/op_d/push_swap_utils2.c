/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:14:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/16 11:16:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;

	if (a->size < 2)
		return ;
	first = a->head;
	a->head = first->next;
	a->head->prev = NULL;
	first->next = NULL;
	a->tail->next = first;
	first->prev = a->tail;
	a->tail = first;
}

void	rb(t_stack *b)
{
	ra(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*last;

	if (a->size < 2)
		return ;
	last = a->tail;
	a->tail = last->prev;
	a->tail->next = NULL;
	last->prev = NULL;
	last->next = a->head;
	a->head->prev = last;
	a->head = last;
}

void	rrb(t_stack *b)
{
	rra(b);
}