/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:17:11 by pfu               #+#    #+#             */
/*   Updated: 2019/08/15 12:17:44 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1new;
	unsigned char	*s2new;

	i = 0;
	s1new = (unsigned char *)s1;
	s2new = (unsigned char *)s2;
	while (i < n)
	{
		if (*(s1new + i) != *(s2new + i))
			return (*(s1new + i) - *(s2new + i));
		i++;
	}
	return (0);
}
