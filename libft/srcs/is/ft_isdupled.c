/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdupled.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:10:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/30 14:15:27 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	isdupled(int n, char **arr)
{
	int i;
	char *arg;
	char *token;
	long num;
	t_bool seen[20001];

	i = 0;
	*seen = false;
	while (++i < n)
	{
		arg = arr[i];
		token = ft_strtok(arg, " ");
		while (token != NULL)
		{
			num = ft_atol(token);
			if (*token != '\0' && num == 0)
				ft_error("", 2);
			if (num < 0)
				num += 10000;
			if (seen[num])
				ft_error("", 2);
			seen[num] = true;
			token = ft_strtok(NULL, " ");
		}
	}
}