/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:14:43 by pfu               #+#    #+#             */
/*   Updated: 2019/08/11 15:32:01 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**strarry;
	int		n;

	n = 0;
	if (s == NULL)
		return (NULL);
	strarry = (char **)malloc(sizeof(char *) * (ft_word_split_count(s, c) + 1));
	if (strarry == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			strarry[n] = ft_word_malloc(s, c);
			n++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	strarry[n] = 0;
	return (strarry);
}
