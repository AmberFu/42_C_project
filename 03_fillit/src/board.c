/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:58 by pfu               #+#    #+#             */
/*   Updated: 2019/11/11 23:24:18 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_board(void)
{
	char	**board;
	int		r;
	int		c;

	r = -1;
	board = (char **)malloc(sizeof(char *) * g_size);
	if (board == NULL)
		return (NULL);
	while (++r < g_size)
	{
		if ((board[r] = ft_strnew(g_size + 1)) == NULL)
			return (NULL);
		ft_bzero(board[r], g_size + 1);
		c = -1;
		while (++c < g_size)
			board[r][c] = '.';
	}
	return (board);
}

void	free_board(char **board)
{
	int i;

	i = -1;
	while (++i < g_size)
		free(board[i]);
	free(board);
}

void	reset_board(char **board, char ch, char flag)
{
	int	r;
	int	c;

	if (flag == '-')
		g_tmp--;
	r = -1;
	while (++r < g_size)
	{
		c = -1;
		while (++c < g_size)
		{
			if (board[r][c] == ch)
				board[r][c] = '.';
		}
	}
}

void	print_board(char **board)
{
	int r;

	r = -1;
	while (++r < g_size)
		ft_putendl(board[r]);
}
