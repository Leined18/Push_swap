/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 00:53:51 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/15 01:09:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	splitStack(t_stack *stack, t_stack **left, t_stack **right)
{
	int		mid;
	t_node	*current;

	if (stack == NULL || stack->size < 2)
	{
		*left = stack;
		*right = NULL;
		return ;
	}
	mid = stack->size / 2;
	current = stack->head;
	while (mid > 1)
	{
		current = current->next;
		mid--;
	}
	*left = stack;
	*right = (t_stack *)malloc(sizeof(t_stack));
	(*right)->head = current->next;
	(*right)->tail = stack->tail;
	(*right)->size = stack->size - stack->size / 2;
	current->next = NULL;
	(*right)->head->prev = NULL;
	(*left)->tail = current;
	(*left)->size = stack->size / 2;
}

static t_stack	*mergeNode(t_stack *merged, t_node *temp, int k)
{
	if (merged->tail == NULL)
	{
		merged->head = temp;
		merged->tail = temp;
		temp->prev = NULL;
	}
	else
	{
		merged->tail->next = temp;
		temp->prev = merged->tail;
		merged->tail = temp;
	}
	merged->size++;
	while (merged->size > k + 1)
	{
		merged->head = merged->head->next;
		free(merged->head->prev);
		merged->head->prev = NULL;
		merged->size--;
	}
	return (merged);
}

static t_stack	*mergeMain(t_stack *left, t_stack *right, int k)
{
	t_stack	*merged;
	t_node	*temp;

	merged = (t_stack *)malloc(sizeof(t_stack));
	merged->head = NULL;
	merged->tail = NULL;
	merged->size = 0;
	while (left != NULL && right != NULL)
	{
		temp = NULL;
		if (left->head->num <= right->head->num)
		{
			temp = left->head;
			left->head = left->head->next;
		}
		else
		{
			temp = right->head;
			right->head = right->head->next;
		}
		merged = mergeNode(merged, temp, k);
	}
	return (merged);
}

t_stack	*mergeStacks(t_stack *left, t_stack *right, int k)
{
	t_stack	*merged;
	t_stack	*rest;
	t_node	*temp;

	merged = mergeMain(left, right, k);
	if (left != NULL)
		rest = left;
	else
		rest = right;
	while (rest != NULL)
	{
		temp = rest->head;
		rest->head = rest->head->next;
		merged = mergeNode(merged, temp, k);
	}
	return (merged);
}
