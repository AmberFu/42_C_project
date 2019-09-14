/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfu <spashleyfu@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:22:25 by pfu               #+#    #+#             */
/*   Updated: 2019/09/13 18:45:55 by pfu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * FOR sepstr_bynl():
 * Input a string with newline char, return the index of newline char.
 * */

size_t	first_nl_index(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/*
 * Description:
 * 		Check fdarray[fd] have newline or not?
 * 		If yes, seprate ori fdarray[fd] into *line and new fdarray[fd].
 *
 * Input: file descriptor, pointer to string which will desplay in main function &
 * 		Stastic fdarray.
 * Output: 
 * 		return 0: means input str (fdarray[fd]) doesn't have any newline.
 * 		return 1: means input str (fdarray[fd]) have newline. 
 * 			Then, process fdarray[fd] into *line (Befor '\n') + new string (After '\n'),
 * 			and new string is new fdarray[fd]! (remember free original fdarray[fd]!)
 * */

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

/*
 * Description:
 * 		When fdarray[fd] is empty or fdarray[fd] string has no newline,
 * 		read() from file (save in buffer), 
 * 		then use this function to join buffer and ori fdarray[fd].
 *
 * Input: File descriptor, buffer from read function, fdarray.
 * Output: NA
 * Process: Join original fdarray[fd] with buffer (read in string from read() function).
 * 			So, you will get new fdarray[fd] string. (re-allocate & free ori string)
 * */

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

/*
 * If read() function return 0, means the function reach the End Of File (EOF).
 * Then, check if fdarray[fd] is NULL.
 * If yes, just return 0.
 * Otherwise, put the rest of fdarray[fd] as *line, and return 1 
 * to print out latest part in file. (from latest newline to EOF)
 * */

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

/*
 * Create Static 2D array's index to hold different file descriptor's read-in string:
 * 		static *fdarray: |0|1|2|3|4|5|6|... each place can hold a string.
 * Use read() to read file (every time read BUFF_SIZE of char),
 * and get size to know exactly byte you read in:
 * 		if size > 0: successfully read something and size is how many size it reads.
 * 		if size == 0: reach EOF.
 * 		if size < 0: something went wrong...error occur.
 * -> Need use bzero to initialize buf[BUFF_SIZE] memory...it maybe some garbage there.
 * */

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
