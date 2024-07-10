# get_next_line

`get_next_line` is a function in C that reads a line from a file descriptor (file or standard input) and returns it without the newline character. This project includes both the standard version (`get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`) and a bonus version (`get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`) which supports multiple file descriptors.

## Files

- **get_next_line.c**: Main function implementation for reading a line from a file descriptor.
- **get_next_line_utils.c**: Utility functions used by `get_next_line.c` for operations like memory management and string manipulation.
- **get_next_line.h**: Header file containing function prototypes and necessary macros for the standard version.
- **get_next_line_bonus.c**: Main function implementation for the bonus version supporting multiple file descriptors.
- **get_next_line_utils_bonus.c**: Utility functions used by `get_next_line_bonus.c` for the bonus version.
- **get_next_line_bonus.h**: Header file containing function prototypes and macros for the bonus version.
- **tests/***: Directory containing tests used in main.

## Compilation

To compile the project, you can compile with gcc. Here's an example compilation command:

```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c && ./a.out
```

Contributors
[pschemit](https://github.com/pschemit)
