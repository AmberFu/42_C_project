/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:21:49 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 10:47:33 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*onebyte_array;
	size_t	i;

	i = 0;
	if (!dst && !src && n > 0)
		return (NULL);
	onebyte_array = (char *)dst;
	while (i < n)
	{
		onebyte_array[i] = *(char *)(src + i);
		i++;
	}
	return (dst);
}
