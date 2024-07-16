
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

void	free_stacks(t_stack *a, int size)
{
	t_node	*current;
	t_node	*prev;
	int		i;

	if (a == NULL || size <= 0)
		return ;
	current = a->tail;
	i = size;
	while (i >= 0 && current != NULL)
	{
		prev = current->prev;
		free(current);
		current = prev;
		i--;
	}
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	free(a);
}

void	ft_add_back(t_stack **stack, t_stack *new_stack)
{
	if (!stack || !new_stack)
		return ;
	if (!*stack)
	{
		*stack = new_stack;
		return ;
	}
	if (!(*stack)->tail)
	{
		(*stack)->head = new_stack->head;
		(*stack)->tail = new_stack->tail;
		(*stack)->size = new_stack->size;
	}
	else
	{
		(*stack)->tail->next = new_stack->head;
		if (new_stack->head)
			new_stack->head->prev = (*stack)->tail;
		(*stack)->tail = new_stack->tail;
		(*stack)->size += new_stack->size;
	}
	free(new_stack);
}

void	ft_add_front(t_stack **stack, t_stack *new_stack)
{
	if (!stack || !new_stack)
		return ;
	if (!*stack)
	{
		*stack = new_stack;
		return ;
	}
	if (!(*stack)->head)
	{
		(*stack)->head = new_stack->head;
		(*stack)->tail = new_stack->tail;
		(*stack)->size = new_stack->size;
	}
	else
	{
		(*stack)->head->prev = new_stack->head;
		new_stack->head->next = (*stack)->head;
		(*stack)->head = new_stack->head;
		(*stack)->size += new_stack->size;
	}
	free(new_stack);
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
	new_node->num = num;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_stack->head = new_node;
	new_stack->tail = new_node;
	new_stack->size = 1;
	return (new_stack);
}

void	ft_load_stack(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	*token;

	i = 1;
	*stack = NULL;
	while (i < argc)
	{
		token = ft_strtok(argv[i], " ");
		while (token != NULL)
		{
			j = 0;
			while (token[j])
			{
				if (!ft_isdigit(token[j]))
					ft_error("is not digit", 2);
				j++;
			}
			num = ft_atoi(token);
			ft_add_back(stack, ft_new(num));
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}
