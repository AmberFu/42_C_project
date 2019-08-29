/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:14:04 by pfu               #+#    #+#             */
/*   Updated: 2019/08/16 20:19:33 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	slen = 0;
	while (dst[dlen] && dlen < dstsize)
		dlen++;
	if (dlen < ft_strlen(dst))
		return (dlen + ft_strlen(src));
	while (src[slen] && (dlen + slen + 1) < dstsize)
	{
		dst[dlen + slen] = src[slen];
		slen++;
	}
	dst[dlen + slen] = '\0';
	return (dlen + ft_strlen(src));
}
