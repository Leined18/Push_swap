/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:41:56 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/13 17:38:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bintostr(const char *bin, char *str)
{
	size_t	bin_len;
	size_t	i;
	size_t	j;

	if (!bin || !str)
		return ;
	i = 0;
	j = 0;
	bin_len = ft_strlen(bin);
	while (j < bin_len)
	{
		ft_bintoa(bin, &str[i], &j);
		i++;
	}
	str[i] = '\0';
}
