/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:12:52 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/30 15:17:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_numbers(const char *str)
{
	int count = 0;
	int in_number = 0;

	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (!in_number)
			{
				in_number = 1;
				count++;
			}
		}
		else
			in_number = 0;
		str++;
	}
	return (count);
}