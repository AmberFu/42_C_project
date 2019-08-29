/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 22:29:18 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 17:11:59 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;

	if (*needle == '\0')
		return ((char *)haystack);
	str = (char *)haystack;
	while (*str)
	{
		if (ft_check_substr(str, needle))
			return (str);
		str++;
	}
	return (NULL);
}
