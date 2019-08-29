/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:42:25 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 17:09:37 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	chr;
	size_t	len;
	size_t	i;

	i = 1;
	len = ft_strlen(s) + 1;
	chr = (char)c;
	str = (char *)s;
	while (*str && *str != chr)
	{
		i++;
		str++;
	}
	if (i == len)
	{
		if (c == 0)
			return (str);
		else
			return (NULL);
	}
	return (str);
}
