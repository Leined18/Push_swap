/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:54:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/16 14:08:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_node	*current;

	if (a)
	{
		ft_printf("Pila a: ");
		current = a->head;
		while (current != NULL)
		{
			ft_printf("(%d) ", current->num);
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
			ft_printf("(%d) ", current->num);
			current = current->next;
		}
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		ft_error("", 1);
	ft_load_stack(&a, ac, av);
	ft_stack_zero(&b, ac);
	printf("Pila antes de ordenar:\n");
	print_stack(a, b);
	ft_printf("size a %d , b %d\n", a->size, b->size);
	free_stack(a, a->size);
	free_stack(b, b->size);
	ft_successful("liberada");
	return (0);
}
