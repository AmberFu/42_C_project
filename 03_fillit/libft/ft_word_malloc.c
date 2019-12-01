/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:17:49 by pfu               #+#    #+#             */
/*   Updated: 2019/08/11 15:30:57 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_word_malloc(char const *s, char c)
{
	int		j;
	char	*word;

	j = 0;
	while (s[j] != '\0' && s[j] != c)
		j++;
	word = (char *)malloc(sizeof(char) * (j + 1));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (s[j] != '\0' && s[j] != c)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}
