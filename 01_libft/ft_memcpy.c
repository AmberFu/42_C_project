/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:21:49 by pfu               #+#    #+#             */
/*   Updated: 2019/08/12 10:23:18 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*onebyte_array;
	size_t	i;

	i = 0;
	onebyte_array = (char *)dst;
	while (i < n)
	{
		onebyte_array[i] = *(char *)(src + i);
		i++;
	}
	return (dst);
}
