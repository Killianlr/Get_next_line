/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kle-rest <kle-rest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:00:56 by kle-rest          #+#    #+#             */
/*   Updated: 2022/11/24 13:19:51 by kle-rest         ###   ########.fr       */
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

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*sc;

	sc = s;
	i = 0;
	if (c > 127)
		return (sc);
	while (sc[i])
	{
		if (sc[i] == c)
			return (&sc[i]);
		i++;
	}
	if (sc[i] == c)
		return (&sc[i]);
	return (0);
}

void	*ft_calloc(int nmemb, int size)
{
	char	*str;
	int	i;

	str = NULL;
	i = 0;
	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > 4294967295 / size)
		return (0);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	while (i < size * nmemb)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s12;
	int		len;

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
	s12[i] = 0;
	return (s12);
}