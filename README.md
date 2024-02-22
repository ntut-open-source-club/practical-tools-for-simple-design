# Practical Tools for Simple Design

###### Officially Supported Platforms and IDEs

|                                | Windows | macOS | Linux |
|:------------------------------:|:-------:|:-----:|:-----:|
|             CLion              |    V    |   V   |   V   |
|        VSCode[^codeoss]        |    V    |   V   |   V   |
| Visual Studio[^novs][^vsmacos] |    ?    |   X   |   X   |
|             No IDE             |    V    |   V   |   V   |

[^vsmacos]: [Microsoft Kills Visual Studio for Mac](https://visualstudiomagazine.com/articles/2023/08/30/vs-for-mac-retirement.aspx)
[^codeoss]: On Linux the support of Code - OSS and VSCodium aren't guaranteed.
[^novs]: Due to lack of testing there may or may not be more issues on VS. Anyway, building PTSD on VS is available.

## Getting Started

Required: Git, CMake, C/C++ Compiler, OpenGL Implementation

Optional: Ninja Build, Clang

> You might get some issue like https://github.com/ntut-open-source-club/practical-tools-for-simple-design/issues/78 check it if you need.

### Command Line

[//]: # (TODO: No IDE Quick Start)
> [!WARNING]  
> This section is work in progress.

```
git clone https://github.com/ntut-open-source-club/practical-tools-for-simple-design.git
cd practical-tools-for-simple-design
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

[//]: # (TODO: VSCode Quick Start)
> [!WARNING]  
> This section is work in progress.

### CLion

[CLion Quick Start](.github/docs/CLionQuickStart/CLionQuickStart.md)

###### NOTE: If you have time, read [OOP2023f Environment Setup](https://hackmd.io/@OOP2023f/rk2-8cVCh)

## Generate Doxygen Documents

Required: Doxygen 1.9.6

```
doxygen docs/Doxyfile
```

Open the generated documents with your favorite browser at `docs/html/index.html`
