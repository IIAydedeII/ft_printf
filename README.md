*This project has been created as part of the 42 curriculum by adede.*

# ft_printf

## Description

**ft_printf** is a custom C library that mimics the behavior of the standard `printf()` function that handles formatted output for multiple data types. This implementation is not expected to replicate the internal buffer management and handle some other specifiers.

This subject reinforces:

- Variable argument handling (va_start, va_arg, va_copy, va_end)
- System write calls
- Modular function declarations

## Implemented Features

### Supported Specifiers

This function supports the following conversion specifiers:

|	Conversion		|	Description									|
|-------------------|-----------------------------------------------|
|	%**c**			|	Prints a single character					|
|	%**s**			|	Prints a string								|
|	%**p**			|	Prints a pointer in hexadecimal format		|
|	%**d**, %**i**	|	Prints a signed decimal integer				|
|	%**u**			|	Prints an unsigned decimal integer			|
|	%**x**			|	Prints a number in hexadecimal (lowercase)	|
|	%**X**			|	Prints a number in hexadecimal (uppercase)	|
|	%**%**			|	Prints a literal percent sign				|

### Formatting Options (Bonus)

Options comply with this generalized pattern:

```c
%[flags][width][.precision]specifier
```

`[width]`: Specifies the minimum number of characters to output

`[.precision]`: For integer types, sets the **minimum** number of digits printed; for the *string* type, sets the **maximum** number of characters printed.

The following are the flags:

|	Flags		|	Description									|
|---------------|-----------------------------------------------|
|	`-`			|	Align to the left							|
|	`0`			|	Pad numeric output with zeros				|
|	`#`			|	Add base prefix for the hexadecimal values	|
|	`+`			|	Always print sign for numbers				|
|	`(space)`	|	Print space for positive numbers			|

## Instructions

### Compilation
To compile the library, run:

```bash
make
```

This will generate the `libftprintf.a` static library.

### Usage
To use `ft_printf` in your projects, include the header:

```c
#include "includes/ft_printf.h"
```

and link the library during compilation:

```bash
gcc main.c -L. -lftprintf
```

### Cleaning

To clean object files:

```bash
make clean
```

To clean everything, including the library:

```bash
make fclean
```

To recompile:

```bash
make re
```

### Bonus

To compile bonus object files:

```bash
make bonus
```

## Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, number: %d, hex: %x\n", "world", 42, 255);
    return 0;
}
```

## Resources
- [`printf` reference](https://en.cppreference.com/w/c/io/fprintf.html)
- [Variadic functions](https://en.cppreference.com/w/c/variadic.html)
- [File descriptors](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)

### AI Usage
AI tools were used to:
- Create unit tests and inform about edge cases.
- Provide explanations for complex C concepts.
- Educate about real world uses of the functions that this library implements.

No AI was used to generate the library code **directly**; all functions were personally implemented but assistively tested.
