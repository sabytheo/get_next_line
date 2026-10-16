*This project has been created as part of the 42 curriculum by tsaby.*

# get_next_line

## Description

**get_next_line** is a C function that reads a file descriptor **one line at a time**, built as part of the 42 curriculum.

```c
char	*get_next_line(int fd);
```

Each call returns the next line of the file, including the trailing `\n` if there is one, or `NULL` when there is nothing left to read or an error occurred. The returned string is allocated and must be freed by the caller.

The difficulty is that `read()` does not know what a line is: it returns `BUFFER_SIZE` bytes at a time, which may contain half a line, several lines, or the end of the file. The function therefore keeps the bytes read after the last `\n` in a **static buffer** between two calls, and keeps reading and joining chunks until it finds a newline or reaches the end of the file.

It works with any `BUFFER_SIZE` (from 1 to very large values), with files, standard input and other file descriptors.

## Instructions

`BUFFER_SIZE` is set at compile time (default: 42):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl files/multiple_line_with_nl
```

`main.c` is a small test program that prints every line of the file given as argument. The `files/` folder contains edge cases: empty file, only newlines, no final newline, lines around `BUFFER_SIZE`, giant lines...

To use it in a project:

```c
#include "get_next_line.h"

char	*line;
while ((line = get_next_line(fd)) != NULL)
{
	/* ... */
	free(line);
}
```

## Files

| File | Content |
|---|---|
| `get_next_line.c` | the function and its static buffer |
| `get_next_line_utils.c` | string helpers (length, join, search) |
| `get_next_line.h` | prototype and default `BUFFER_SIZE` |
| `main.c`, `files/` | test program and test files |

## Resources

- `man 2 read`
- [Static variables in C](https://en.wikipedia.org/wiki/Static_variable)
- [gnlTester](https://github.com/Tripouille/gnlTester)
