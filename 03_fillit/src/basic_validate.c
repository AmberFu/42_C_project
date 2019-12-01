/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlin <mlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:34:19 by pfu               #+#    #+#             */
/*   Updated: 2019/11/12 14:25:20 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		set_pcs(int r, int c)
{
	if (g_tmp < 8)
	{
		g_pcs[g_pcn].coords[g_tmp++] = r + '0';
		g_pcs[g_pcn].coords[g_tmp++] = c + '0';
	}
	else
		return (-1);
	return (0);
}

int		verify_pcs(char input[BUF], int i)
{
	int	row;
	int	col;

	row = 0;
	while ((i + 1) % 21 != 0)
	{
		while (row < 4)
		{
			col = 0;
			while (col < 5)
			{
				if (col == 4 && input[i] != '\n')
					return (-1);
				if (col != 4 && input[i] != '.' && input[i] != '#')
					return (-1);
				if (input[i] == '#')
					if (set_pcs(row, col))
						return (-1);
				col++;
				i++;
			}
			row++;
		}
	}
	return (0);
}

int		read_pcs(char input[BUF], int size)
{
	int	i;

	g_pcn = 0;
	i = 0;
	while (input[i] != '\0')
	{
		g_tmp = 0;
		if (verify_pcs(input, i) < 0)
			return (-1);
		g_pcn++;
		i = i + 19;
		if (++i != size)
		{
			if (input[i++] != '\n')
				return (-1);
		}
	}
	return (0);
}

int		readfile_verify(char input[BUF], int size)
{
	if ((size > (BUF - 1)) || (size % 21 != 20))
		return (-1);
	if (read_pcs(input, size) < 0 || g_pcn > 26)
		return (-1);
	init_shape();
	align_pcs();
	if (verify_shape() < 0)
		return (-1);
	return (0);
}
