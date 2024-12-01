/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:47:56 by tsaby             #+#    #+#             */
/*   Updated: 2024/11/28 17:53:34 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*scrap = NULL;
	ssize_t		*nb_read;
	char		*buff;

	if (fd == -1 || BUFFER_SIZE < 1)
	{
		ft_str_free(&scrap);
		return (NULL);
	}
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nb_read = read(fd, buff, BUFFER_SIZE);
	if (nb_read == -1)
	{
		free(buff);
		ft_str_free(&scrap);
		return (NULL);
	}
	buff[(int)nb_read] = '\0';
	if (nb_read == 0)
		return ();
	return ();
}

void	ft_str_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
