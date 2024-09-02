/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:05:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/09/02 14:51:13 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_valid_numbers(const char *str)
{
	int		j;
	int		count;
	char	c;

	j = 0;
	count = 0;
	while (str[j] != '\0')
	{
		c = str[j];
		if (ft_isdigit(c) && (str[j + 1] == ' ' || str[j + 1] == '\0'))
			count++;
		j++;
	}
	return (count);
}

static int	validate_tokens(const char *str)
{
	int		j;
	char	c;

	j = 0;
	while (str[j] != '\0')
	{
		c = str[j];
		if (c == '-' || c == '+')
		{
			if (!ft_isdigit(str[j + 1]) || str[j + 1] == '\0' || (j > 0
					&& ft_isdigit(str[j - 1])))
				return (0);
		}
		else if (!ft_isdigit(c) && !ft_isspace(c))
			return (0);
		j++;
	}
	return (1);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (!validate_tokens(argv[i]))
			ft_error("Error\n", 1);
		count += count_valid_numbers(argv[i]);
		i++;
	}
	return (count);
}

void	check_range(char **s_numbers, int *numbers)
{
	int	i;

	i = 0;
	while (s_numbers[i])
	{
		if (ft_atoll(s_numbers[i]) > INT_MAX || ft_atoll(s_numbers[i]) < INT_MIN
			|| ft_strlen(s_numbers[i]) > 11)
		{
			free_2d(s_numbers);
			free(numbers);
			ft_error("Error\n", 1);
		}
		i++;
	}
}
