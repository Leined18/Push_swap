
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:08:54 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/09 11:08:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_atobin(unsigned char c, char *ret, size_t *j)
{
	int k;

	k = 7;
	if (!ret)
		return ;
	while (k >= 0)
	{
		if (c & (1 << k))
			ret[*j] = '1';
		else
			ret[*j] = '0';
		(*j)++;
		k--;
	}
	ret[*j] = '\0';
}