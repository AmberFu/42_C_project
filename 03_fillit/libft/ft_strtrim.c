/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:29:31 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 19:52:09 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	l_index(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	return (i);
}

static size_t	r_index(char const *s)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n'))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	l_ind;
	unsigned int	r_ind;
	unsigned int	new_len;
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	l_ind = l_index(s);
	r_ind = r_index(s);
	if (ft_strlen(s) == 0 || l_ind > r_ind)
		return (ft_strnew(0));
	new_len = r_index(s) - l_ind;
	str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!str)
		return (NULL);
	while (s[l_ind + i] != '\0' && (l_ind + i) < r_ind)
	{
		str[i] = s[l_ind + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
