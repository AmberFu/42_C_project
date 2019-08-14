/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:35:22 by pfu               #+#    #+#             */
/*   Updated: 2019/08/05 20:37:42 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b_char;

	b_char = (char *)b;
	while (len > 0)
	{
		b_char[len - 1] = c;
		len--;
	}
	return ((void *)b_char);
}
