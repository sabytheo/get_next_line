#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    static char *saved_data = NULL;
    char *posnewline = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0'; // Terminer la chaîne lue
        printf("Buffer read: %s\n", buffer); // Debug print

        char *temp = ft_strjoin(saved_data, buffer);  // Créer la nouvelle chaîne
        if (!temp)  // Vérifier l'échec de malloc
            return (NULL);
        free(saved_data);  // Libérer l'ancienne mémoire de saved_data
        saved_data = temp; // Réassigner à saved_data
        printf("Saved data: %s\n", saved_data); // Debug print

        // Vérifier la présence d'un '\n'
        posnewline = ft_strchr(saved_data, '\n');
        if (posnewline)
        {
            line = ft_substr(saved_data, 0, posnewline - saved_data + 1);
            char *temp2 = ft_strdup(posnewline + 1); // Sauvegarder les données restantes
            free(saved_data);
            saved_data = temp2;
            printf("Line: %s\n", line); // Debug print
            return (line);
        }
    }

    if (bytes_read < 0) // Erreur lors de la lecture
        return (NULL);
    if (saved_data && *saved_data) // Traiter les données restantes dans `saved_data` si la fin du fichier est atteinte
    {
        line = ft_strdup(saved_data);
        free(saved_data);
        saved_data = NULL;
        printf("Line: %s\n", line); // Debug print
        return (line);
    }
    free(saved_data);
    saved_data = NULL;
    return (NULL);
}
