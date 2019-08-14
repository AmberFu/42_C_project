/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:17:25 by pfu               #+#    #+#             */
/*   Updated: 2019/08/07 12:53:53 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	mem = (char *)malloc(size);
	if (mem == NULL)
		return (NULL);
	while (size > 0)
	{
		mem[size - 1] = 0;
		size--;
	}
	return ((void *)mem);
}
