/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_atoistr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:16:53 by pfu               #+#    #+#             */
/*   Updated: 2019/08/26 23:36:20 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_valid_atoistr(char *str)
{
	int				i;

	i = 0;
	while (*str)
	{
		while (ft_escape_valid_atoi(*str))
			str++;
		if (i == 0 && (*str < 48 || *str > 57))
		{
			if (*str != '+' && *str != '-')
				return (0);
		}
		else if (i == 0 && *str >= 48 && *str <= 57)
			return (1);
		else if (i > 0 && *str >= 48 && *str <= 57)
			return (1);
		else if (i > 0 && (*str < 48 || *str > 57))
			return (0);
		str++;
		i++;
	}
	return (1);
}
