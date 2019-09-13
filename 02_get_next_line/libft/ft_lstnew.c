/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:30:07 by pfu               #+#    #+#             */
/*   Updated: 2019/08/26 19:18:44 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cp_cont(void *dst, void const *src, size_t n)
{
	char	*dst_c;
	size_t	i;

	i = 0;
	dst_c = (char *)dst;
	while (i < n)
	{
		dst_c[i] = *(char *)(src + i);
		i++;
	}
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(*newlist));
	if (!newlist)
		return (NULL);
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = malloc(content_size);
		if (!newlist->content)
			return (NULL);
		ft_cp_cont(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
