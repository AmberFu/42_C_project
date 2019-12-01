/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:32:23 by pfu               #+#    #+#             */
/*   Updated: 2019/11/11 23:22:57 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_pcs(char **board, int r, int c, char ch)
{
	int		r_move;
	int		c_move;
	int		i;

	i = 0;
	if (board[r][c] == '.')
		board[r][c] = ch;
	else
		return (-1);
	while (i <= 4)
	{
		if ((r < 0 || r >= g_size) || (c < 0 || c >= g_size))
			return (-1);
		r_move = g_pcs[g_tmp].coords[i + 2] - g_pcs[g_tmp].coords[i];
		c_move = g_pcs[g_tmp].coords[i + 3] - g_pcs[g_tmp].coords[i + 1];
		if (r + r_move >= 0 && r + r_move < g_size && c + c_move >= 0 &&
				c + c_move < g_size && board[r + r_move][c + c_move] == '.')
			board[r + r_move][c + c_move] = ch;
		else
			return (-1);
		r += r_move;
		c += c_move;
		i += 2;
	}
	return (0);
}

int		solve_board(char **board, char ch)
{
	int		r;
	int		c;

	r = -1;
	if (g_tmp == g_pcn)
		return (0);
	while (++r < g_size)
	{
		c = -1;
		while (++c < g_size)
		{
			if (board[r][c] == '.' && put_pcs(board, r, c, ch) == 0)
			{
				g_tmp++;
				if (solve_board(board, ch + 1) == 0)
					return (0);
				else
					reset_board(board, ch, '-');
			}
			else
				reset_board(board, ch, ' ');
		}
	}
	return (-1);
}

int		solve(void)
{
	char	ch;
	char	**board;

	g_size = 2;
	board = NULL;
	ch = 'A';
	while (g_size * g_size < g_pcn * 4)
		g_size++;
	if ((board = create_board()) == NULL)
		return (-1);
	g_tmp = 0;
	while (solve_board(board, ch) < 0)
	{
		free_board(board);
		g_size++;
		g_tmp = 0;
		ch = 'A';
		if ((board = create_board()) == NULL)
			return (-1);
	}
	print_board(board);
	free_board(board);
	return (0);
}
