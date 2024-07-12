
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

void	ft_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

void	ft_add_front(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

t_stack	*ft_new(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_load_stack(int argc, char **argv, t_stack **stack)
{
	int i;
	int j;
	int num;
	char *token;

	i = 1;
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
			num = atoi(token);
			ft_add_back(stack, ft_new(num));
			token = ft_strtok(NULL, " ");
		}
		i++;
	}
}
