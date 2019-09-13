/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:16:04 by pfu               #+#    #+#             */
/*   Updated: 2019/09/11 20:02:31 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_c;
	char	*src_c;
	size_t	i;

	i = -1;
	if ((!dst && !src && len > 0) || !src || !dst)
		return (NULL);
	src_c = (char *)src;
	dst_c = (char *)dst;
	if (src_c > dst_c)
	{
		while (++i < len)
			dst_c[i] = src_c[i];
	}
	else
	{
		while (len-- > 0)
			dst_c[len] = src_c[len];
	}
	return (dst);
}
