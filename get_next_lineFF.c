/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:17:21 by kle-rest          #+#    #+#             */
/*   Updated: 2022/11/24 09:15:57 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

#define BUFFER_SIZE 7

char	*ft_resetmemo(char *memo)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = memo;
	while (tmp[i - 1] != '\n')
		i++;
	if (tmp[i] != '\n' && tmp[i] != '\0')
		tmp = ft_savememo(&tmp[i]);
	else
		tmp = ft_strdup("");
	free(memo);
	return (tmp);
}

int	ft_memcheck(char *memo)
{
	int		i;

	i = 0;
	if (!memo)
		return (0);
	while (memo[i])
	{
		if (memo[i] == '\n')
			return (1);
		i++;
	}
	if (memo[i] == '\n')
		return (1);
	return (0);
}

char	*ft_readandfill(char *memo, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	int		e;

	e = 0;
	printf("hey");
	while (e == 0);
	{
		ret = read(fd, buf, BUFFER_SIZE);
		memo = ft_strjoin(memo, buf);
		if (ft_memcheck(memo) == 1)
			e = 1;
	}
	return (memo);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*memo;

	if (!memo)
		memo = malloc(0);
	else if (ft_memcheck(memo) == 1)
	{
		line = ft_strdup(memo);
		memo = ft_resetmemo(memo);
		return (line);
	}
	memo = ft_readandfill(memo, fd);
	line = ft_strdup(memo);
	memo = ft_resetmemo(memo);
	return (line);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("l1 = %s", line);
	printf("-------------------\n");
	free(line);
	line = get_next_line(fd);
	printf("l2 = %s", line);
	printf("-------------------\n");
	free(line);
	line = get_next_line(fd);
	printf("l3 = %s", line);
	printf("-------------------\n");
	free(line);
	line = get_next_line(fd);
	printf("l4 = %s", line);
	printf("-------------------\n");
	free(line);
	return (0);
}