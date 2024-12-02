#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    char *line;
    printf("Reading lines from file '%s':\n", argv[1]);
    while ((line = get_next_line(fd)))
    {
        printf("Read line: |%s|\n", line);
        free(line);
    }
    printf("Finished reading file.\n");

    close(fd);
    return (0);
}
