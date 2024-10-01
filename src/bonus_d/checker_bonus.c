/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:46:20 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/01 12:30:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	instructions(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa", 5) || !ft_strncmp(line, "sa\n", 5))
		swap(a, 'a', FALSE);
	else if (!ft_strncmp(line, "sb", 5) || !ft_strncmp(line, "sb\n", 5))
		swap(b, 'b', FALSE);
	else if (!ft_strncmp(line, "ss", 5) || !ft_strncmp(line, "ss\n", 5))
		swap_both(a, b, FALSE);
	else if (!ft_strncmp(line, "pa", 5) || !ft_strncmp(line, "pa\n", 5))
		push(a, b, 'b', FALSE);
	else if (!ft_strncmp(line, "pb", 5) || !ft_strncmp(line, "pb\n", 5))
		push(b, a, 'a', FALSE);
	else if (!ft_strncmp(line, "ra", 5) || !ft_strncmp(line, "ra\n", 5))
		rotate(a, 'a', FALSE);
	else if (!ft_strncmp(line, "rb", 5) || !ft_strncmp(line, "rb\n", 5))
		rotate(b, 'b', FALSE);
	else if (!ft_strncmp(line, "rr", 5) || !ft_strncmp(line, "rr\n", 5))
		rotate_both(a, b, FALSE);
	else if (!ft_strncmp(line, "rra", 5) || !ft_strncmp(line, "rra\n", 5))
		reverse_rotate(a, 'a', FALSE);
	else if (!ft_strncmp(line, "rrb", 5) || !ft_strncmp(line, "rrb\n", 5))
		reverse_rotate(b, 'b', FALSE);
	else if (!ft_strncmp(line, "rrr", 5) || !ft_strncmp(line, "rrr\n", 5))
		reverse_rotate_both(a, b, FALSE);
	else
		return (1);
	return (0);
}

static void	read_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL || line[0] == '\n')
		{
			if (line)
				free(line);
			break ;
		}
		if (instructions(a, b, line))
			ft_error("Error\n", 1);
		free(line);
	}
}

static void	checker(t_stack *a, t_stack *b)
{
	read_instructions(a, b);
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	b;
	int		*num;
	int		count;

	if (ac == 1)
		return (0);
	count = check_digits(ac, av);
	num = parse(ac, av, count);
	if (count < 1 || ft_isndup(num, count))
	{
		free(num);
		if (count == 1)
			ft_error("", 1);
		ft_error("Error\n", 1);
	}
	ft_load_stack(&a, count, num);
	b.head = NULL;
	b.size = 0;
	checker(a, &b);
	return (0);
}
