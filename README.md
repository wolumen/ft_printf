# ft_printf

## Description

This project consists of programming a library that contains a simplified version of the printf function. Only a limited selection of functions may be used.  
The core element is to learn about variadic arguments.   
All code has to compile with -Wall -Werror -Wextra and to be free of possible memory leaks.


### Allowed functions

```
malloc, free, write, 
va_start, va_arg, va_copy, va_end
```

## Mandatory Part

It must not do the buﬀer management like the real printf.   
It manages the following conversions:

  ```
cspdiuxX%
  ```

To be able to distinguish the self-written functions, they have been prefixed with ft.


## Objectives

* C Basics
* Libc
* Static library generation


## Skills

* Rigor
* Algorithms & AI


## Getting Started

### Clone the repository
```shell
git clone git@github.com:wolumen/ft_printf.git
cd ft_printf
```

### Compiling
Run the following commands:

* To compile the ft_printf.a file
		
		make
* To remove objects:

		make clean
* To remove objects and binary file:

        make fclean
* To re-compile:

		make re

