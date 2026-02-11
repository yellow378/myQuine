# AGENTS.md

This document provides guidelines for agentic coding assistants working in this repository.

## Project Overview

This is a **C Quine project** - a self-replicating program that outputs its own source code. The repository contains:
- `main.c` - The main quine implementation
- `convert.py` - Utility script for escaping/quoting transformations
- `.clang-format` - Code formatting configuration

## Build Commands

### C Compilation

**Compile the main program:**
```bash
gcc -Wall -Wextra -std=c99 -o main main.c
```

**Compile with debug symbols:**
```bash
gcc -g -Wall -Wextra -std=c99 -o main main.c
```

**Compile with optimizations:**
```bash
gcc -O2 -Wall -Wextra -std=c99 -o main main.c
```

### Python Scripts

**Run the converter script:**
```bash
python3 convert.py
```

### Code Formatting

**Format C files with clang-format:**
```bash
clang-format -i main.c
```

**Check formatting without modifying files:**
```bash
clang-format --dry-run main.c
```

## Linting

**Basic C linting (using compiler warnings):**
```bash
gcc -Wall -Wextra -pedantic -std=c99 -o main main.c
```

## Testing

This project has a simple test to verify the quine property:

**Test that main outputs itself:**
```bash
gcc -std=c99 -o main main.c && ./main > output.c && diff main.c output.c && echo "Quine test passed!"
```

## Code Style Guidelines

### C Style

- **Indentation:** 4 spaces (no tabs)
- **Line length:** Maximum 80 characters
- **Brace style:** K&R style (opening brace on same line)
- **Pointer alignment:** Asterisk on the right side of type names
- **Column limit:** 80 characters (enforced by `.clang-format`)

### Naming Conventions

- **Functions:** `snake_case` for helper functions
- **Variables:** `snake_case` for local variables
- **Constants:** `UPPER_SNAKE_CASE` for constants
- **Macros:** `UPPER_SNAKE_CASE`

### Import Organization (C)

1. System includes (`<stdio.h>`, `<string.h>`, etc.)
2. Local project includes
3. Sort includes alphabetically within each category

### Error Handling

- Always check return values from system calls
- Use `perror()` for system errors
- Return meaningful exit codes (0 for success, non-zero for errors)
- Handle `NULL` pointer returns from memory allocation

### General Guidelines

- Keep functions focused and under 50 lines when possible
- Use descriptive variable names (avoid single letters except loop counters)
- Add comments for non-obvious logic
- Use `const` for read-only values
- Prefer `sizeof(variable)` over `sizeof(type)`
- Avoid magic numbers; use named constants

### Python Style

- Follow PEP 8 guidelines
- Use snake_case for functions and variables
- Add docstrings to functions
- Keep line length under 100 characters

## Special Notes

- This is a **quine** - be careful when modifying the source code as any change must preserve the self-replicating property
- The `.clang-format` file defines the canonical C formatting - run `clang-format` before committing
- The `convert.py` script is used to generate escaped/quoted versions of the source code

## Git Workflow

- Create feature branches for changes
- Write clear commit messages
- Run formatting and tests before committing
- Review changes with `git diff` before committing

## Single Test Command

**Run the quine verification test:**
```bash
gcc -std=c99 -o main main.c && ./main > output.c && diff main.c output.c && echo "Quine test passed!"
```

## Development Tips

- Before modifying the quine, understand how self-reproducing programs work
- The quine has two parts: code that prints data, and data that describes the code
- Use `diff` to verify changes haven't broken the self-reproducing property
- The `convert.py` script helps generate the data section from the source code
- Test after every modification to ensure the quine property is maintained

## Common Tasks

**Rebuild and test:**
```bash
gcc -std=c99 -o main main.c && ./main > output.c && diff main.c output.c
```

**Format code:**
```bash
clang-format -i main.c
```

**Generate escaped source:**
```bash
python3 convert.py
```

**View current source:**
```bash
cat main.c
```

## Constraints

- The C99 standard is required (`-std=c99`)
- Code must work with standard gcc without special flags
- No external libraries beyond standard C library
- The program must compile without warnings with `-Wall -Wextra`
