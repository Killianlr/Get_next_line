/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:18:20 by kle-rest          #+#    #+#             */
/*   Updated: 2022/11/24 13:55:55 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

#define BUFFER_SIZE 10

char	*ft_free(char *buf_save, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(buf_save, buffer);
	free(buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buf_save)
{
	char	*buffer;
	int		ret;

	ret = 1;
	buffer = ft_calloc(BUFFER_SIZE, 1);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf_save);
			return (0);
		}
		buffer[ret] = 0;
		buffer = ft_free(buf_save, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			buf_save = ft_strchr(buffer, '\n');
			break ;
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char *buf;
	char		*line;

	if (fd < 0 || fd > 16 || BUFFER_SIZE <= 0 || !buf)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_line(buf);
	buf = ft_next(buf);
	
}

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("L1 = %s", line);
	free(line);
	line = get_next_line(fd);
	printf("L2 = %s", line);
	free(line);
	line = get_next_line(fd);
	printf("L3 = %s", line);
	free(line);
	line = get_next_line(fd);
	printf("L4 = %s", line);
	free(line);
}