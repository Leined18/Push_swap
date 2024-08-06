/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:54:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/08/06 19:20:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, t_stack *b, int *nb, int c)
{
	t_node	*tmp;

	b->head = NULL;
	b->size = 0;
	ins_sort(nb, c);
	tmp = a->head;
	while (tmp)
	{
		tmp->index = ft_index(tmp->data, nb);
		tmp = tmp->next;
	}
}

int	*get_num(t_stack *a, int size)
{
	t_node	*current;
	int		*n;
	int		i;

	n = (int *)ft_calloc(sizeof(int), size);
	if (!n)
		return (NULL);
	i = -1;
	current = a->head;
	while (current && ++i <= size)
	{
		n[i] = current->data;
		current = current->next;
	}
	return (n);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	b;
	int		*num;

	if (ac == 1)
		ft_error("", 1);
	check(ac, av);
	ft_load_stack(&a, ac, av);
	num = get_num(a, a->size);
	check_range(a, num);
	init(a, &b, num, a->size);
	sort(a, &b, num, a->size);
	free(num);
	free_stacks(a, &b);
	return (0);
}
