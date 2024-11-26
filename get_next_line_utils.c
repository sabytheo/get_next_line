/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:35:03 by tsaby             #+#    #+#             */
/*   Updated: 2024/11/25 12:54:09 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while ((unsigned char)s[i] && i != start)
		i++;
	if (len > ft_strlen(s) - i)
		len = ft_strlen(s) - i;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (j < len)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tabjoin;
	size_t	i;
	size_t	j;
	size_t len1;
	size_t len2;

	len1 = s1 ? ft_strlen(s1) : 0;
	len2 = s2 ? ft_strlen(s2) : 0;
	i = 0;
	j = 0;
	tabjoin = malloc(sizeof(char) * (len1 + len2 + 1));
    while (i < len1)
    {
        tabjoin[i] = s1[i];
        i++;
    }
    while (j < len2)
    {
        tabjoin[i + j] = s2[j];
        j++;
    }
    tabjoin[i + j] = '\0';
    return (tabjoin);
}


char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	dest = (char *)malloc((srclen + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (c > 127)
		c = c - 128;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
