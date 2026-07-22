# Raylib-boilerplate

A minimal C++ raylib boilerplate for Neovim.

## Prerequisites

- [raylib](https://www.raylib.com/) installed system-wide
- g++ with C++14 support
- pkg-config

## Usage

```
make          # build
make run      # build & run
make debug    # debug build
make clean    # clean artifacts
```

Or in Neovim: press `F5` to build & run, `F6` for debug build & run.

## Project structure

```
├── src/
│   └── main.cpp      # entry point
├── obj/               # build output (gitignored)
├── Makefile
├── .nvim.lua          # Neovim project config
└── .gitignore
```

## Customizing

Add new `.cpp` files in `src/` — the Makefile picks them up automatically via wildcard.
