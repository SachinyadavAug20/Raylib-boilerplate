# $(Game Title)

![$(Game Title)](screenshots/screenshot000.png)

*$(Short one-line game description)*

## Description

> $(A longer, more detailed description of your game. What is it about? What makes it interesting?)

## Features

- $(Feature 1)
- $(Feature 2)
- $(Feature 3)

## Controls

Keyboard:

- $(Key) — $(Action)
- $(Key) — $(Action)
- $(Key) — $(Action)

## Screenshots

*TODO: Show your game to the world, animated GIFs recommended!*

## Developers

- $(Your Name) — $(Role / Tasks Developed)

## Links

- Gameplay Video: $(YouTube Link)
- Itch.io Release: $(itch.io Game Page)

## License

This project sources are licensed under an unmodified <a href="LICENSE">zlib/libpng</a> license.

Copyright (c) 2026 Sachin

---

## Development Setup

A minimal C++17 raylib boilerplate with an industry-standard project layout.

### Prerequisites

- [raylib](https://www.raylib.com/) installed system-wide
- g++ with C++17 support
- pkg-config

### Commands

```
make              # build (outputs to build/game)
make run          # build & run
make debug        # debug build with -g -O0
make clean        # clean build artifacts
```

Or in Neovim: press `F5` to build & run, `F6` for a debug build & run.

### Project structure

```
├── include/
│   └── resource_dir.h  # robust asset-path resolution
├── resources/          # game assets (images, audio, fonts)
├── src/
│   └── main.cpp        # entry point
├── build/              # compiled binary output (gitignored)
├── obj/                # object files (gitignored)
├── Makefile
└── .nvim.lua           # Neovim project configuration
```

### Customizing

Add new `.cpp` files in `src/` — the Makefile picks them up automatically via
wildcard. Place sprites, sounds, and fonts in `resources/` and load them by
relative path; `resource_dir.h` keeps asset paths working no matter which
directory the binary is launched from.