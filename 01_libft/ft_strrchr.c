/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:27:53 by pfu               #+#    #+#             */
/*   Updated: 2019/08/16 22:21:16 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
		str++;
	if (c == 0)
		return (str);
	while (*str != (char)c && i > 0)
	{
		str--;
		i--;
	}
	if (i == 0)
	{
		if (*str == (char)c)
			return (str);
		else
			return (NULL);
	}
	else
		return (str);
}
