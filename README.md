<div align="center">

# my_printf
### Epitech - C Programming Essentials | Year 1

![Language](https://img.shields.io/badge/language-C-blue)
![Year](https://img.shields.io/badge/year-2023-lightgrey)
![Grade](https://img.shields.io/badge/grade-75%2F92_tests-brightgreen)

</div>

Reimplementation of the C standard `printf` function from scratch. The project is compiled into a static library (`libmy.a`) and supports the same conversion specifiers and flag modifiers as the real thing.

## How it works

The entry point in `my_printf.c` iterates over the format string character by character. When it hits a `%`, it hands off to a dispatcher that figures out which handler to call based on the next character.

The dispatcher (`do_flag.c`) uses a function pointer array of 257 entries indexed directly by the specifier character. So `array['d']` points to `do_flag_d`, `array['e']` to `do_flag_e`, and so on. No switch, no if-else chain. Calling `array[flag](list, length, param)` gets you to the right handler in one step.

Between the `%` and the specifier, there can be flags (`-`, `+`, `0`, space), a field width, a precision, and a length modifier. The `give_flag_parameters` function in `utility/` extracts all of that as a string and passes it down to each handler so they can apply padding and alignment themselves.

```
myprintf/
├── my_printf.c              # format string loop
├── include/
│   ├── my.h                 # all prototypes
│   └── flag.h               # per-specifier handler prototypes
├── flags/
│   ├── do_flag.c            # dispatch table
│   ├── do_flags.c           # %c and %s
│   ├── do_flag_d.c          # %d / %i
│   ├── do_flag_x.c          # %x / %X (hex)
│   ├── do_flag_u.c          # %u (unsigned)
│   ├── do_flag_f.c          # %f (float)
│   ├── do_flag_e.c          # %e / %E (scientific notation)
│   ├── do_flag_g.c          # %g / %G
│   ├── do_flag_p.c          # %p (pointer)
│   ├── do_flag_n.c          # %n (write-back)
│   ├── do_flag_percent.c    # %%
│   └── do_flag_base.c       # generic base conversion
├── put/                     # output primitives with length tracking
├── length_put/              # same functions but return length without printing
└── utility/                 # string helpers, parameter parsing, padding
```

Supported specifiers: `%d %i %c %s %x %X %o %u %f %e %E %F %g %G %p %n %%`

## Building

```bash
make        # produces libmy.a
make clean  # remove object files
make fclean # remove object files and libmy.a
make re     # rebuild from scratch

# link against the library in your own project
gcc main.c -L. -lmy -o myprogram
```

## A few things worth noting

Padding requires knowing the output length before you start printing. Rather than buffering everything into a string, there is a parallel set of `length_put_*` functions that compute how many characters a given value would take without actually writing anything. The handler calls the length version first, figures out how much padding to add, writes the padding, then writes the value. It is a bit more code but avoids any dynamic allocation for output.

Scientific notation (`%e`) is done manually: divide (or multiply for values < 1) by 10 in a loop until `1 <= mantissa < 10`, counting iterations to get the exponent, then format the mantissa via `my_put_float` and append `e+XX` by hand. Negative exponents go the other way, multiplying until the value crosses 1.

Every output function takes an `int *length` and increments it as it writes. This threads through the entire call stack so that `my_printf` can return the total number of characters written at the end, matching the contract of the real `printf`.

---

Built as part of my Epitech curriculum (Promo 2028).
Check the rest of my projects at [github.com/FLOWleplusbeau](https://github.com/FLOWleplusbeau).
