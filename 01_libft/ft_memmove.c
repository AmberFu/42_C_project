/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:16:04 by pfu               #+#    #+#             */
/*   Updated: 2019/08/13 23:55:45 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_tmp;
	char	*dst_c;
	size_t	i;

	i = 0;
	dst_c = (char *)dst;
	src_tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (src_tmp == NULL)
		return (NULL);
	while (i < len)
	{
		src_tmp[i] = *(char *)(src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst_c[i] = src_tmp[i];
		i++;
	}
	free(src_tmp);
	return (dst);
}
