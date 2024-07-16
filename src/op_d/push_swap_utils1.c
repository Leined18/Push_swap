/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:13:41 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/16 11:14:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->size < 2)
		return ;
	first = a->head;
	second = a->head->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	a->head = second;
	if (a->tail == second)
		a->tail = first;
}

void	sb(t_stack *b)
{
	sa(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*first_b;

	if (b->size == 0)
		return ;
	first_b = b->head;
	b->head = first_b->next;
	if (b->head != NULL)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	first_b->next = a->head;
	if (a->head != NULL)
		a->head->prev = first_b;
	else
		a->tail = first_b;
	a->head = first_b;
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	pa(b, a);
}