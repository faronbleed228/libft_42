*This project has been created as part of the 42 curriculum by ypopovyc.*

---

# libft

## Description

**libft** is a custom C library built from scratch as the very first project of the 42 curriculum. The goal is to re-implement a selection of standard C library functions (`libc`), along with additional utility functions that are useful across future 42 projects.

By writing each function by hand — without relying on the standard library — the project builds a deep understanding of low-level memory management, string manipulation, linked lists, and how the C standard library actually works under the hood.

The resulting static library (`libft.a`) is designed to be reused and extended throughout the entire 42 cursus.

---

## Library Overview

The library is organized into four groups:

### Part 1 — Libc Functions

Re-implementations of standard C library functions, behaving identically to their originals:

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if a character is alphabetic |
| `ft_isdigit` | Checks if a character is a decimal digit |
| `ft_isalnum` | Checks if a character is alphanumeric |
| `ft_isascii` | Checks if a character is a valid ASCII character |
| `ft_isprint` | Checks if a character is printable |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes out a block of memory |
| `ft_memcpy` | Copies memory from one area to another |
| `ft_memmove` | Copies memory handling overlapping regions |
| `ft_strlcpy` | Size-bounded string copy |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_toupper` | Converts a character to uppercase |
| `ft_tolower` | Converts a character to lowercase |
| `ft_strchr` | Locates a character in a string (first occurrence) |
| `ft_strrchr` | Locates a character in a string (last occurrence) |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Searches memory for a byte |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring within a string (bounded) |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates zero-initialized memory |
| `ft_strdup` | Duplicates a string using `malloc` |

### Part 2 — Additional Functions

Utility functions not found in `libc` but commonly needed:

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Trims leading and trailing characters from a set |
| `ft_split` | Splits a string by a delimiter into an array |
| `ft_itoa` | Converts an integer to a string |
| `ft_strmapi` | Applies a function to each character, returning a new string |
| `ft_striteri` | Applies a function to each character in-place |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

### Part2 — Linked List Functions

Functions for manipulating singly-linked lists using the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize` | Counts the number of nodes in a list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstdelone` | Deletes a single node using a provided function |
| `ft_lstclear` | Deletes and frees all nodes in a list |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Instructions

### Requirements

- A C compiler: `cc` (or `gcc` / `clang`)
- `make all`

### Compilation

Clone the repository and compile the library:

```bash
git clone <your-repo-url>
cd libft
make
```

This produces `libft.a` — the static library archive.

Available `make` rules:

| Rule | Action |
|---|---|
| `make all` | Same as `make` — explicitly compiles all source files |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `all` |

### Usage in a Project

To use `libft` in another C project:

1. Copy or reference `libft.a` and `libft.h` in your project.
2. Include the header:

```c
#include "libft.h"
```

3. Compile your project with the library:

```bash
cc your_file.c -L. -lft -o your_program
```

Here's what each flag means:

- `cc your_file.c` — compiles your source file with the C compiler.
- `-L.` — tells the linker to look for libraries in the current directory (`.`), where `libft.a` lives.
- `-lft` — links against `libft`. The `-l` flag strips the `lib` prefix and `.a` suffix, so `-lft` resolves to `libft.a`.
- `-o your_program` — sets the name of the output executable.

---

## Resources

### Documentation & References

- [linux.die.net — Linux man pages](https://linux.die.net/man/3/strcpy)
- [Portfolio Courses — YouTube channel](https://www.youtube.com/@PortfolioCourses)

### AI Usage

AI (Claude by Anthropic) was used in the following ways during this project:

- **Conceptual clarification**: Asking for plain-English explanations of how functions like `memmove`, `strlcpy`, and `strlcat` are supposed to behave, especially around edge cases and boundary conditions.
- **Debugging assistance**: Describing incorrect outputs and getting help identifying logical errors in implementations (e.g., off-by-one errors in `ft_substr` or null-terminator handling).
- **README drafting**: Generating the structure and initial content of this README file.

The original curriculum implementation was written by the student. The maintenance fixes and regression tests described below were prepared with OpenAI Codex.

## List ownership and public regressions

`ft_lstnew(NULL)` returns an allocated node with NULL content and NULL next.
It returns NULL only if node allocation fails. `ft_lstmap` accepts NULL content
returned by its callback; NULL content is not itself an allocation failure.
The caller supplies callbacks that can handle such content. If a node cannot be
allocated, the delete callback releases the newly mapped content and all content
already added to the result; the source list is preserved.

```sh
make re
make test
```

The Linux/GCC regression target uses a malloc wrapper and ASan/UBSan to test
allocation failures at every output node, cleanup, NULL content, empty input,
and missing callbacks. Set `SANITIZERS=` for an unsanitized build.
The 2026-10-21 environment required `ASAN_OPTIONS=detect_leaks=0`;
LeakSanitizer could not inspect its threads. No full 42 moulinette is included.

Maintenance fixes and public tests were prepared with OpenAI Codex.
