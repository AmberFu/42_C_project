/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:45:35 by pfu               #+#    #+#             */
/*   Updated: 2019/11/12 14:42:41 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_zero(char input[BUF])
{
	int	i;

	i = -1;
	ft_bzero(input, BUF);
	while (++i < 26)
		ft_bzero(g_pcs[i].coords, 9);
}

int		error_exit(void)
{
	ft_putstr("error\n");
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		size;
	char	input[BUF];

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	set_zero(input);
	if (((fd = open(av[1], O_RDONLY)) < 0) ||
			((size = read(fd, input, BUF)) <= 0))
		return (error_exit());
	if (readfile_verify(input, size) < 0)
		return (error_exit());
	if (close(fd) < 0)
		return (error_exit());
	free_shape();
	if (solve() < 0)
		return (error_exit());
	return (0);
}
