/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:27:04 by danpalac          #+#    #+#             */
/*   Updated: 2024/08/12 10:39:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(char *err, t_bool yeet)
{
	write(2, "\033[1;31m", 7);
	write(2, err, ft_strlen(err));
	write(2, "\033[0m", 4);
	if (yeet)
		exit(EXIT_FAILURE);
}
