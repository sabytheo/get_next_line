/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaby <tsaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:35:12 by tsaby             #+#    #+#             */
/*   Updated: 2024/11/24 13:19:42 by tsaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    static char *saved_data = NULL;
    char *posnewline = NULL;
    char *line;

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        if (bytes_read == 0)
            break;
        buffer[bytes_read] = '\0';
        saved_data = ft_strjoin(saved_data, buffer);
        if (!saved_data)
            return (NULL);
        posnewline = ft_strchr(saved_data, '\n');
        if (posnewline)
        {
            line = ft_substr(saved_data, 0, posnewline - saved_data + 1);
            char *temp = ft_strdup(posnewline + 1);
            free(saved_data);
            saved_data = temp;
            return (line);
        }
    }
    if (saved_data && *saved_data)
    {
        line = ft_strdup(saved_data);
        free(saved_data);
        saved_data = NULL;
        return (line);
    }
    return (NULL);

}
