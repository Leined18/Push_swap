/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:36:13 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/15 01:08:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	mergeSortKSorted(t_stack **stack, int k)
{
	t_node	*current;

	if (*stack == NULL || (*stack)->size < 2)
	{
		return ;
	}
	t_stack *left, *right;
	splitStack(*stack, &left, &right);
	mergeSortKSorted(&left, k);
	mergeSortKSorted(&right, k);
	*stack = mergeStacks(left, right, k);
	current = (*stack)->head;
	while (current->next != NULL)
	{
		current->next->prev = current;
		current = current->next;
	}
	(*stack)->tail = current;
}

void	push(t_stack **stack, int num, int index)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	new_node->num = num;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
		(*stack)->size = 1;
	}
	else
	{
		new_node->prev = (*stack)->tail;
		(*stack)->tail->next = new_node;
		(*stack)->tail = new_node;
		(*stack)->size++;
	}
}