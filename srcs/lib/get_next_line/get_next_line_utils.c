/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:47:10 by mmateo-t          #+#    #+#             */
/*   Updated: 2019/12/09 20:31:01 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(char *s1)
{
	char	*s2;
	int		i;
	int		size;

	size = ft_strlen(s1);
	i = 0;
	s2 = (char*)malloc(sizeof(char) * size + 1);
	if (s2 == NULL)
	{
		return (s2);
	}
	while (i <= size)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (substr);
	while (s[i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char		*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return ((char*)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char*)s);
	}
	return (NULL);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	strjoin = (char*)malloc(sizeof(char) * (i + j + 1));
	if (strjoin == NULL)
		return (strjoin);
	i = 0;
	j = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}
