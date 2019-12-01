/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:22:25 by pfu               #+#    #+#             */
/*   Updated: 2019/09/15 14:51:42 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	first_nl_index(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int		sepstr_bynl(const int fd, char **line, char **fdarray)
{
	size_t	index;
	size_t	len;
	char	*new;

	if ((ft_strchr(fdarray[fd], '\n')) == NULL)
		return (0);
	index = first_nl_index(fdarray[fd]);
	*line = ft_strsub(fdarray[fd], 0, index);
	len = ft_strlen(fdarray[fd]);
	if ((len - index - 1) == 0)
	{
		free(fdarray[fd]);
		fdarray[fd] = NULL;
	}
	else
	{
		new = ft_strsub(fdarray[fd], (index + 1), (len - index - 1));
		free(fdarray[fd]);
		fdarray[fd] = new;
	}
	return (1);
}

void	keepbuf_for_specificfd(const int fd, char *buf, char **fdarray)
{
	size_t	buflen;
	size_t	keeplen;
	char	*new;

	buflen = ft_strlen(buf);
	if (fdarray[fd] == NULL)
	{
		if (!(new = (char *)malloc(sizeof(char) * (buflen + 1))))
			return ;
		new = ft_memmove((void *)new, (void *)buf, (buflen + 1));
	}
	else
	{
		keeplen = ft_strlen(fdarray[fd]);
		new = ft_strjoin(fdarray[fd], buf);
		free(fdarray[fd]);
	}
	fdarray[fd] = new;
}

int		process_end(char **fdarray, char **line, const int fd)
{
	if (fdarray[fd] != '\0')
	{
		*line = ft_strdup(fdarray[fd]);
		free(fdarray[fd]);
		fdarray[fd] = NULL;
		return (1);
	}
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*fdarray[4864];
	char		buf[BUFF_SIZE + 1];
	ssize_t		size;

	ft_bzero(buf, BUFF_SIZE + 1);
	if (fd < 0 || !line || (read(fd, buf, 0)) < 0)
		return (-1);
	if (fdarray[fd] != '\0' && sepstr_bynl(fd, line, (char **)fdarray) == 1)
		return (1);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		keepbuf_for_specificfd(fd, buf, (char **)fdarray);
		if (sepstr_bynl(fd, line, (char **)fdarray) == 1)
			break ;
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (size == 0)
		return (process_end(fdarray, line, fd));
	else if (size < 0)
		return (-1);
	else
		return (1);
}
