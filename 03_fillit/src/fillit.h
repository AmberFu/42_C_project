/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlin <mlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:42:05 by pfu               #+#    #+#             */
/*   Updated: 2019/11/12 14:25:23 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF 546

# include <stdio.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_tetros
{
	char			coords[9];
}					t_tetros;

t_tetros			g_pcs[26];
int					g_pcn;
int					g_tmp;
char				*g_shape[19];
int					g_size;

void				set_zero(char input[BUF]);
int					error_exit(void);
void				free_shape(void);

/*
** Verify Tetriminos:
*/
int					readfile_verify(char input[BUF], int size);
int					read_pcs(char input[BUF], int size);
void				init_shape(void);
int					verify_shape(void);
int					set_pcs(int r, int c);
int					verify_pcs(char input[BUF], int i);
void				align_pcs(void);
char				get_min(char c, char s[8]);

/*
** Solve Problem:
*/
int					solve(void);
char				**create_board(void);
int					solve_board(char **board, char ch);
int					put_pcs(char **board, int r, int c, char ch);
void				reset_board(char **board, char ch, char flag);
void				print_board(char **board);
void				free_board(char **board);

#endif
