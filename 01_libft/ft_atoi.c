/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:45:22 by pfu               #+#    #+#             */
/*   Updated: 2019/08/27 17:15:07 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intstr_positive_negative(char *s)
{
	if (*s == '-')
		return (-1);
	else
		return (1);
}

static int		ft_has_sign(char *s)
{
	if (*s == '-' || *s == '+')
		return (1);
	else
		return (0);
}

static size_t	get_valid_atoistr_index(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (i > 0 && (s[i] < 48 || s[i] > 57))
			return (i);
		i++;
	}
	return (i);
}

static int		calculate_ans(char *s, size_t len, int positive_negative,
		int has_sign)
{
	int	ans;

	ans = 0;
	while (len > 0)
	{
		if (len == 1 && positive_negative < 0)
			break ;
		else if (len == 1 && has_sign == 1)
			break ;
		else
			ans += (s[len - 1] - '0') * positive_negative;
		len--;
		positive_negative *= 10;
	}
	return (ans);
}

int				ft_atoi(const char *str)
{
	int		positive_negative;
	int		has_sign;
	int		ans;
	size_t	len;
	char	*s;

	ans = 0;
	s = (char *)str;
	if (*str == '\0')
		return (0);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	if (ft_valid_atoistr(s) == 0)
		return (0);
	while (ft_escape_valid_atoi(*s))
		s++;
	positive_negative = ft_intstr_positive_negative(s);
	has_sign = ft_has_sign(s);
	len = get_valid_atoistr_index(s);
	ans = calculate_ans(s, len, positive_negative, has_sign);
	return (ans);
}
