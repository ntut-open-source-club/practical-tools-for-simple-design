# Code Styles and Guidelines

## General

* Use UTF-8 encoding
* Windows should use CRLF line breaks, MacOS and Linux(Unix-like OSes) should use LF line breaks
* Use `enum class` over `enum`
    https://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
    https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/
* Line break at EOF
    https://stackoverflow.com/questions/729692/why-should-text-files-end-with-a-newline
    Force it in VSCode
    https://stackoverflow.com/questions/44704968/visual-studio-code-insert-newline-at-the-end-of-files
* Write portable code by following C++ standards and avoid using `#pragma` directives
* Add line breaks wherever it makes sense
* Use primary operators instead of alternative  ones([ref](https://en.cppreference.com/w/cpp/language/operator_alternative))

## Includes

Use `#ifndef` for include guards instead of `#pragma once`

Include guard format: `<NAMESPACE>_<FILENAME>_<FILE_EXTENSION>` 

E.g.: Include guard for `GameObject.hpp` should be `GAME_OBJECT_HPP` 

Internal header should use `""` and external headers should use `<>`

Unless specified, included headers should be the following order:

1. definition header(if needed)
2. system header
3. external header
4. internal header

Different categories are separated with line breaks. If headers are in the same category, headers for the same libraries should be grouped together and be in alphabetical order

E.g. includes for `Player.cpp` should be

```cpp=
#include "Player.hpp"

#include <string>
#include <vector>

#include <spdlog/spdlog.h>

#include "Math/Vector2.hpp"

// ...
```

See also: https://clangd.llvm.org/guides/include-cleaner

## Class

Member functions and variables declaration should be in the following order, access specifiers should be in the order of `public` -> `protected` -> `private`. Static members should be declared above normal members.

1. Functions
    1. Constructor
        1. Default
        2. Parameterized
        3. Copy
        4. Move
    2. Destructor
    3. Operator overload
        1. Copy assignment
        2. Move assignment
    4. Getter
    5. Setter
    6. Other
2. Variables

Follow C++ rule of three/five/zero
    https://en.cppreference.com/w/cpp/language/rule_of_three

## File Types

C source file: `.c`
C header file: `.h`
C++ source file: `.cpp`
C++ header file: `.hpp`

Vertex Shader: `.vert`
Fragment Shader: `.frag`

## File and Folder Naming

Source and header files should be `PascalCase` if it defines a class or struct, otherwise it should be `snake_case`

Top level folders should only consist of a single word and be `lowercase` (e.g. `src/`, `include/`, `lib/`)

Source and header file folders should be `PascalCase` and be the same name as its namespace

E.g.: `include/Math/Vector2.hpp` should be:

```cpp=
#ifndef MATH_VECTOR2_HPP
#define MATH_VECTOR2_HPP

namespace Math {
class Vector2 {
public:
    Vector2();

}
}

#endif

```

## Variable Naming Convention

Lower items override higher items if rules collide

|                     | Case         | Prefix | Suffix |
| ------------------- | ------------ | ------ | ------ |
| Namespace           | `PascalCase` |        |        |
| Class               | `PascalCase` |        |        |
| Class member        | `PascalCase` | `m_`   |        |
| Static class member | `PascalCase` | `s_`   |        |
| Struct              | `PascalCase` |        |        |
| Struct member       | `camelCase`  |        |        |
| Enum                | `PascalCase` |        |        |
| Enum element        | `UPPER_CASE` |        |        |
| Function/Method     | `camelCase`  |        |        |
| Parameter           | `camelCase`  |        |        |
| Variable            | `camelCase`  |        |        |
| Type Alias/Typedef  | `PascalCase` |        |        |
| Global constant     | `UPPER_CASE` |        |        |
| Macro               | `UPPER_CASE` |        |        |
| Template parameter  | `UPPER_CASE` |        |        |
