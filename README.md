# ft_printf

## Description

This project is realization of `stdio.h` `printf()` function. It was made due to my studying in 21-school, Russia.
The main goal of project - learn how to use variable number of functions argumnets aka `va_arg()`.

`ft_printf()` has reduced functional compareraly to original `printf()`.

## Usage

Run `make` to compile `libftprintf.a` static library. This library provides function `int ft_printf(const char *fmt, ...)`.
Necessary header file `ft_printf.h` locates in root directory.

## Functionality

`ft_printf()` supports:

1. Types
* `%i`, `%d`, `%u`, `%x`, `%X`, `%p`, `%s`, `%c`, `%%` and reduced `%f` (see notes).

2. Flags
* `%0`, `%+`, `%-`, `% `, `%#`.

3. Length
* `h`, `hh`, `l`, `ll`. All length modificators applieble **only for number** types.

4. Width and precision
* Variable width and precision used by `*`.

### Notes

What is not supported that is not supported.

* `%f` type does not support rounding, `%#` flag, work with more than 18-digits numbers.

* Length modifier `l` has no affect on `%c` and `%s` type.
