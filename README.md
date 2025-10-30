# frtclap
### Field-Reflected Type-safe Command-Line Argument Parser

**frtclap** is a modern, reflection-inspired **command-line argument parser** for C++20.  
It aims to offer the expressiveness of [Clap](https://github.com/clap-rs/clap) in Rust,  
combined with the zero-boilerplate style of [Boost.PFR](https://www.boost.org/doc/libs/release/doc/html/boost_pfr.html).

Define your program’s arguments as simple structs — no macros, no registration functions, no DSLs.

```cpp
#include "frtclap.hpp"
#include <cassert>

struct Demo
{
    std::string input;
    std::string output;
};

int main()
{
    const char* args[] = {"demo.exe", "--input", "file.cpp", "--output", "a.out"};

    auto parsed = frtclap::parse<Demo>(static_cast<int>(std::size(args)),
                                       const_cast<char**>(args));

    assert(parsed.input == "file.cpp");
    assert(parsed.output == "a.out");
}
```

---

## ✨ Features

- **Header-only** — just include `frtclap.hpp`
- **No dependencies**
- **C++20** reflection-like syntax via structured bindings and template metaprogramming
- **Automatic flag mapping** from struct member names (`input` → `--input`)
- **Custom renames** for flexible flag naming
- **Subcommands** using variants
- **Type-safe parsing** — populate `int`, `std::string`, `std::vector<T>` directly
- Inspired by **Clap** (Rust) and **Boost.PFR**, but written from scratch

---

## 🧩 Installation

`frtclap.hpp`is completely **header-only** -- there's nothing to build or link.

```cpp
#include "frtclap.hpp"
```

If you prefer to organize it as a submodule:

```bash
git submodule add https://github.com/firaatozkan/frtclap external/frtclap
```
And include it in your project's include path:
```cmake
target_include_directories(your_target PRIVATE external/frtclap)
```

---

## 🚀 Usage Examples

### 1. Basic options

```cpp
struct Args
{
    std::string input;
    std::string output;
};

int main(int argc, char** argv)
{
    auto parsed = frtclap::parse<Args>(argc, argv);

    std::cout << "Input: "  << parsed.input  << "\n";
    std::cout << "Output: " << parsed.output << "\n";
}
```

**CLI:**
```
./app --input main.cpp --output build.o
```

---

### 2. Renaming options

Use `frtclap::rename<T, "flagname">` to customize flag names.

```cpp
struct CustomArgs
{
    frtclap::rename<std::string, "my_input"> input;
    frtclap::rename<std::string, "my_output"> output;
};
```

**CLI:**
```
./app --my_input foo.cpp --my_output bar.o
```

---

### 3. Subcommands

Define subcommands as structs, and wrap them in `frtclap::subcommand<...>`.

```cpp
struct create { std::string filename; };
struct remove { std::string filename; };

struct Command
{
    frtclap::subcommand<create, frtclap::rename<remove, "delete">> cmd;
};
```

**CLI:**
```
./app delete old.txt
```

And handle with `std::visit`:

```cpp
std::visit(overloaded{
    [](const create& c) { /* ... */ },
    [](const remove& r) { std::cout << "Deleting " << r.filename; }
}, parsed.cmd);
```

---

### 4. Vector arguments

You can also accept multiple positional arguments into a `std::vector`.

```cpp
struct accumulate_all
{
    std::vector<int> inputs;
};

struct multiply
{
    int a;
    int b;
};

struct CLI
{
    frtclap::subcommand<accumulate_all, multiply> cmd;
};
```

**CLI:**
```
./app accumulate_all 1 2 3 4 5
```

---

## ⚙️ Design Overview

frtclap works by performing compile-time introspection on user-defined structs.  
For each field, it automatically:

1. Derives a flag name from the member name (e.g. `--input`).
2. Parses arguments according to the member type.
3. For subcommands, dispatches into the correct struct variant.

This approach is heavily inspired by **Boost.PFR**, but all reflection logic is custom written — no external dependencies, no RTTI.

---

## 🧱 Roadmap

- [ ] Automatic help/usage generation  
- [ ] Short flags (`-i`, `-o`)  
- [ ] Default values and optional arguments  
- [ ] Nested subcommands  
- [ ] Validation and custom error reporting  
- [ ] Better diagnostics for invalid CLI input  

---

## 🧪 Requirements

- C++20 compiler (`clang++ >= 12`, `g++ >= 10`, or MSVC 19.30+)
- No external libraries

---

## 📜 License

This project is licensed under the [MIT License](./LICENSE).

---

## 💡 Inspiration

- [Clap (Rust)](https://github.com/clap-rs/clap) — declarative CLI definition  
- [Boost.PFR](https://www.boost.org/doc/libs/release/doc/html/boost_pfr.html) — field reflection in C++  
- [CLI11](https://github.com/CLIUtils/CLI11) — argument parsing and subcommands

---

> ⚠️ **Note:** frtclap is an experimental project.  
> The API is still evolving — expect breaking changes as new features are developed.
