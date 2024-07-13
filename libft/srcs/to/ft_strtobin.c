/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:38:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/13 17:39:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtobin(const char *str, char *bin)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if (!str || !bin)
		return ;
	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (i < len)
	{
		ft_atobin((unsigned char)str[i], bin, &j);
		i++;
	}
	bin[j] = '\0';
}
