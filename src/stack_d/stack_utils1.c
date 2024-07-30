
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:12:28 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/12 13:12:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	while (a)
		del_stack(a);
	while (b)
		del_stack(b);
}

t_stack	*ft_new(int num)
{
	t_stack	*new_stack;
	t_node	*new_node;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free(new_stack);
		return (NULL);
	}
	new_node->data = num;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_stack->head = new_node;
	new_stack->tail = new_node;
	new_stack->size = 1;
	return (new_stack);
}

void	load_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}
