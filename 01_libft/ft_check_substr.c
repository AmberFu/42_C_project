/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_substr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 23:28:38 by pfu               #+#    #+#             */
/*   Updated: 2019/08/16 23:49:54 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_substr(char *str, const char *substr)
{
	size_t	i;

	i = 0;
	while (str[i] == substr[i] && str[i] && substr[i])
		i++;
	if (i == ft_strlen(substr))
		return (1);
	else
		return (0);
}
