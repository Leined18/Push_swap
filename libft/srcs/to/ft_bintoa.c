/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:33 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/13 17:38:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bintoa(const char *bin, char *ascii, size_t *j)
{
	unsigned char	c;
	int				k;

	if (!bin || !ascii)
		return ;
	c = 0;
	k = 0;
	while (k < 8)
	{
		c <<= 1;
		if (bin[*j] == '1')
			c |= 1;
		(*j)++;
		k++;
	}
	*ascii = c;
}
