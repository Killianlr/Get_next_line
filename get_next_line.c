/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:18:20 by kle-rest          #+#    #+#             */
/*   Updated: 2022/11/24 11:37:21 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

#define BUFFER_SIZE 200000

char	*ft_free(char *fuck)
{
	char	*retour;

	retour = fuck;
	free(fuck);
	return (retour);
}

char	*gnl_end(char *memo)
{
	char	*line;

	line = ft_strdup(memo);
	free(memo);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*memo;
	int			ret;
	char		*line;
	char		*tmp;

	if (!memo)
		memo = malloc(0);
	while (ft_memcheck(memo) < 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (0);
		buf[ret] = '\0';
		memo = ft_strjoin(memo, buf);
		if (ret == 0)
			return (gnl_end(memo));
	}
	line = ft_substr(memo, 0, ft_memcheck(memo) + 1);
	line = ft_free(line);
	memo = ft_substr(memo, ft_memcheck(memo) + 1, ft_strlen(memo) - ft_memcheck(memo));
	//memo = ft_free(memo);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("txt", O_RDONLY);
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