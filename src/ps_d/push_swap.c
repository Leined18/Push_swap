/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:54:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/17 21:04:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		ft_error("", 1);
	check(ac, av);
	ft_load_stack(&a, ac, av);
	b = NULL;
	b = ft_calloc(1, sizeof(t_stack));
	sort(a, b, a->size);
	ft_printf("size a: %d\n", a->size);
	free_stacks(a, b, a->size);
	return (0);
}
