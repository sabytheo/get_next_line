/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:35:03 by tsaby             #+#    #+#             */
/*   Updated: 2024/12/01 21:56:14 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*join;

	len = 0;
	while (s2[len] != '\n' && s2[len] != 0)
		len++;
	if (s2[len] == '\n')
		len++;
	join = malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (join == NULL)
		return (free((void *)s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2 && j++ < len)
		join[i + j - 1] = s2[j - 1];
	join[i + j - 1] = 0;
	free((void *)s1);
	return (join);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = 0;
	while (str[len] != '\n' && str[len] != 0)
		len++;
	if (str[len] == '\n')
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (dest);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_stdest(char *src)
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

void	ft_clean(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i + j] != '\0')
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}

int	ft_findchr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
