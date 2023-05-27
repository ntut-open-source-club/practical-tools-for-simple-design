# Practical Tools for Simple Design

## Getting Started

Required: Git, CMake, C/C++ compiler

Optional: Ninja Build, clang

### Command Line

```
git clone https://ntut-open-source-club/practical-tools-for-simple-design.git

cmake -B build
cmake --build build
```

> If Ninja Build is install use `cmake -B build -G Ninja` to speed compile time

> For older versions of CMake(`<3.13`? verification needed) use
> ```
> mkdir build
> cd build
> cmake .
> cmake --build .
> ```
> if the `-B` flag is unsupported

> If using Neovim or other LSP supported editors, append `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` to the generation command for `clangd` to work

### VSCode

TODO

### CLion

TODO

### Visual Studio

TODO

## Generate Doxygen Documents

Required: Doxygen 1.9.6

```
doxygen docs/Doxyfile
```

Open the generated documents with your favorite browser at `docs/html/index.html`
