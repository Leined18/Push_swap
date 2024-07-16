/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:54:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/16 15:21:30 by danpalac         ###   ########.fr       */
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

void	check_duplicates(int argc, char **argv)
{
	int		i;
	char	*arg;
	char	*token;
	long	num;
	bool	seen[20001] = {false};

	i = 0;
	while (++i < argc)
	{
		arg = argv[i];
		token = strtok(arg, " ");
		while (token != NULL)
		{
			num = ft_atol(token);
			if (*token != '\0' && num == 0)
				ft_error("Error: Invalid Argument", 2);
			if (num < 0)
				num += 10000;
			if (seen[num])
				ft_error("Error: Duplicated Number", 2);
			seen[num] = true;
			token = strtok(NULL, " ");
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		ft_error("", 1);
	check_duplicates(ac, av);
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
