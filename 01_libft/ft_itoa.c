/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 23:07:25 by pfu               #+#    #+#             */
/*   Updated: 2019/08/12 00:35:19 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*smallest(char const *str)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*negative_itoa(int n)
{
	char	*s;
	int		len;

	len = get_len(-n) + 1;
	n = -n;
	s = (char *)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (n >= 1)
	{
		s[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	s[len - 1] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	if (n == -2147483648)
		return (smallest("-2147483648"));
	if (n < 0)
		return (negative_itoa(n));
	else
		len = get_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	while (n >= 10)
	{
		s[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	s[len - 1] = n + '0';
	return (s);
}
