/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:28:55 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 16:46:32 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	unsigned char	char_c;
	unsigned int	i;

	i = 0;
	s_cpy = (unsigned char *)s;
	char_c = c;
	while (i < n)
	{
		if (*(s_cpy + i) == char_c)
			return ((void *)(s_cpy + i));
		i++;
	}
	return (NULL);
}
