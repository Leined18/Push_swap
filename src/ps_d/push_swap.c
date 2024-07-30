/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:54:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/30 15:22:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_stack *a, t_stack *b, int *nb, int c)
{
	t_node	*tmp;
	int		i;

	a->head = NULL;
	b->head = NULL;
	a->size = 0;
	b->size = 0;
	i = c - 1;
	while (i >= 0)
	{
		load_stack(a, 0, nb[i]);
		i--;
	}
	ins_sort(nb, c);
	tmp = a->head;
	while (tmp)
	{
		tmp->index = ft_index(tmp->data, nb);
		tmp = tmp->next;
	}
}

static int	*get_num(int argc, char **argv, int count)
{
	char	**s_numbers;
	int		*numbers;
	int		i;
	int		j;
	int		k;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
			ft_error("", 1);
		check_range(s_numbers, numbers);
		k = 0;
		while (s_numbers[k])
			numbers[j++] = ft_atoi(s_numbers[k++]);
		free_2d(s_numbers);
	}
	return (numbers);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		count;
	int		*num;
	int		i;

	if (ac < 2)
		ft_error("", 1);
	count = check(ac, av); // the problem is when av is 1 got only the first num
	num = get_num(ac, av, count); // the problem
	i = -1;
	while (++i < count)
		ft_printf("%d ", num[i]);
	exit(1);
	init(&a, &b, num, count);
	sort(&a, &b, num, count);
	print_stack(&a, &b);
	free(num);
	free_stacks(&a, &b);
	return (0);
}
