/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 11:35:53 by pfu               #+#    #+#             */
/*   Updated: 2019/09/11 19:41:38 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	slen;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || str == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if ((len > slen) || (start > slen) || ((len + start) > slen))
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
