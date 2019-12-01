/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:09:06 by pfu               #+#    #+#             */
/*   Updated: 2019/08/12 20:36:46 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;
	size_t			i;

	i = 0;
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		if (src_c[i] == (unsigned char)c)
			return (&dst_c[i + 1]);
		i++;
	}
	return (NULL);
}
