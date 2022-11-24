/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:00:56 by kle-rest          #+#    #+#             */
/*   Updated: 2022/11/24 11:24:26 by kle-rest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_memcheck(char *memo)
{
	int	i;

	i = 0;
	if (!memo)
		return (-2);
	while (memo[i])
	{
		if (memo[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*sm;

	i = 0;
	sm = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sm)
		return (0);
	while (s[i])
	{
		sm[i] = s[i];
		i++;
	}
	sm[i] = '\0';
	return (sm);
}

char	*ft_substr(char *s, int start, int len)
{
	int	i;
	int	j;
	char	*sm;

	i = 0;
	j = start;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sm = malloc(sizeof(char) * (len + 1));
	if (!sm)
		return (0);
	while (len > 0)
	{
		sm[i] = s[j];
		i++;
		j++;
		len--;
	}
	sm[i] = '\0';
	return (sm);
}


char	*ft_strjoin(char *s1, char *s2)
{
	//printf("ft_join\n");
	int	i;
	int	j;
	char	*s12;
	int	len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s12 = malloc(sizeof(char) * (len + 1));
	if (!s12)
		return (0);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			s12[i] = s1[i];
		else
			s12[i] = s2[j++];
		i++;
	}
	free(s1);
	s12[i] = 0;
	return (s12);
}