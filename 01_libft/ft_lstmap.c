/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:25:10 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 19:58:38 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	newlst = ft_lstnew(lst->content, lst->content_size);
	if (!newlst)
		return (NULL);
	newlst = f(newlst);
	lst = lst->next;
	tmp = newlst;
	while (lst)
	{
		tmp->next = ft_lstnew(lst->content, lst->content_size);
		if (!tmp->next)
			return (NULL);
		tmp->next = f(tmp->next);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (newlst);
}
