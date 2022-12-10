/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:37:40 by kle-rest          #+#    #+#             */
/*   Updated: 2022/12/10 14:49:32 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

#define BUFFER_SIZE 10

char	*ft_next(char *stash)
{
	char	*next;
	int		i;
	int		j;

	next = malloc(sizeof(char) * 10);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	printf("stash === %s\n", stash);
	while (stash[i])
	{
		next[j] = stash[i];
	printf("i = %d\n", i);
	printf("stash[i] ==== %c\n", stash[i]);
	printf("next[j] ==== %c\n", next[j]);
		i++;
		j++;
	}
	printf("next %s\n", next);
	next[j] = '\0';
	return (next);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{ 
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	printf("line ==== %s\n", line);
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*bufread;
	int		ret;

	ret = 1;
	bufread = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ret != 0 && ft_checkline(stash) == 0)
	{
		ret = read(fd, bufread, BUFFER_SIZE);
		if (ret == -1)
		{
			free(bufread);
			return (NULL);
		}
		bufread[ret] = 0;
		stash = ft_strjoin(stash, bufread);
	}
//	printf("bufread %s\n", bufread);
//	printf("stash %s\n", stash);
	free(bufread);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_read(fd, stash);
		if (!stash)
			return (NULL);
	line = ft_line(stash);
	printf("line ==== %s\n", line);
	stash = ft_next(stash);
//	printf("stash %s\n", stash);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("L1 = %s", line);
	free(line);
	return (0);
}