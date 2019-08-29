/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 23:27:22 by pfu               #+#    #+#             */
/*   Updated: 2019/08/17 00:09:40 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	need_len;
	size_t	i;

	i = 0;
	need_len = ft_strlen(needle);
	str = (char *)haystack;
	while (*str && (len - i) >= need_len)
	{
		if (ft_check_substr(str, needle))
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
