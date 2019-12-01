/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlin <mlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:01:51 by pfu               #+#    #+#             */
/*   Updated: 2019/11/11 23:06:57 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_shape(void)
{
	int	i;

	i = -1;
	while (++i < 19)
	{
		free(g_shape[i]);
	}
}

void	init_shape(void)
{
	g_shape[0] = ft_strdup("00011011");
	g_shape[1] = ft_strdup("00102030");
	g_shape[2] = ft_strdup("00010203");
	g_shape[3] = ft_strdup("00010211");
	g_shape[4] = ft_strdup("00101120");
	g_shape[5] = ft_strdup("01101112");
	g_shape[6] = ft_strdup("01101121");
	g_shape[7] = ft_strdup("00011020");
	g_shape[8] = ft_strdup("00011121");
	g_shape[9] = ft_strdup("01112021");
	g_shape[10] = ft_strdup("00102021");
	g_shape[11] = ft_strdup("00101112");
	g_shape[12] = ft_strdup("00101121");
	g_shape[13] = ft_strdup("02101112");
	g_shape[14] = ft_strdup("00010210");
	g_shape[15] = ft_strdup("00010212");
	g_shape[16] = ft_strdup("01101120");
	g_shape[17] = ft_strdup("00011112");
	g_shape[18] = ft_strdup("01021011");
}

char	get_min(char c, char s[8])
{
	int		i;
	char	min;

	if (c == 'r')
	{
		i = 2;
		min = s[0];
		while (i <= 6)
		{
			if (s[i] < min)
				min = s[i];
			i += 2;
		}
		return (min);
	}
	i = 3;
	min = s[1];
	while (i <= 7)
	{
		if (s[i] < min)
			min = s[i];
		i += 2;
	}
	return (min);
}

void	align_pcs(void)
{
	char	row_min;
	char	col_min;
	char	row_ans;
	char	col_ans;
	int		i;

	g_tmp = -1;
	while (++g_tmp < g_pcn)
	{
		row_min = get_min('r', g_pcs[g_tmp].coords);
		col_min = get_min('c', g_pcs[g_tmp].coords);
		i = 0;
		while (i < 8)
		{
			row_ans = (g_pcs[g_tmp].coords[i] - row_min) + '0';
			col_ans = (g_pcs[g_tmp].coords[i + 1] - col_min) + '0';
			g_pcs[g_tmp].coords[i] = row_ans;
			g_pcs[g_tmp].coords[i + 1] = col_ans;
			i += 2;
		}
	}
}

int		verify_shape(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_pcn)
	{
		j = -1;
		g_tmp = 0;
		while (++j < 19)
			if (ft_strcmp(g_pcs[i].coords, g_shape[j]) == 0)
				g_tmp++;
		if (g_tmp != 1)
			return (-1);
	}
	return (0);
}
