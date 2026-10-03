# CMakeLists.txt Usage Guide

## Current Configuration

```cmake
cmake_minimum_required(VERSION 3.20)
project(food_delivery_lld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(
    food_delivery_lld
    main.cpp
    src/model/User.cpp
    src/model/Customer.cpp
    src/model/Address.cpp
)
```

## Key Components Explained

| Command | Purpose |
|---------|---------|
| `cmake_minimum_required(VERSION 3.20)` | Minimum CMake version required |
| `project(food_delivery_lld)` | Project name (used for target names) |
| `set(CMAKE_CXX_STANDARD 17)` | Use C++17 standard |
| `set(CMAKE_CXX_STANDARD_REQUIRED ON)` | Enforce C++17 (fail if not available) |
| `include_directories(include)` | Add `include/` to header search path |
| `add_executable(...)` | Define executable target with source files |

## Adding New Source Files

### Option 1: Explicit Listing (Current - Recommended for small projects)

Edit `CMakeLists.txt` and add each `.cpp` file:

```cmake
add_executable(
    food_delivery_lld
    main.cpp
    src/model/User.cpp
    src/model/Customer.cpp
    src/model/Address.cpp
    src/model/Restaurant.cpp      # Add new files here
    src/service/OrderService.cpp  # Add new files here
    # ... more files
)
```

### Option 2: Auto-Discovery (For larger projects)

Replace explicit listing with `file(GLOB_RECURSE ...)`:

```cmake
file(GLOB_RECURSE SOURCES
    "src/**/*.cpp"
    "main.cpp"
)

add_executable(food_delivery_lld ${SOURCES})
```

**Note:** With `GLOB_RECURSE`, you must re-run CMake configure (`cmake_configure.bat`) when adding new files.

## Adding Include Directories

For subdirectories under `include/`:

```cmake
include_directories(include)
# Already covers: include/model/, include/service/, etc.
```

## Build Configurations

```cmake
# Debug build (default)
cmake --build build --config Debug

# Release build (optimized)
cmake --build build --config Release

# RelWithDebInfo (release with debug symbols)
cmake --build build --config RelWithDebInfo

# MinSizeRel (minimum size release)
cmake --build build --config MinSizeRel
```

## Common CMake Commands

```cmd
# Configure (run in VS Developer Command Prompt)
cmake -B build -G "Visual Studio 17 2022" -A x64

# Build
cmake --build build --config Release

# Clean build
cmake --build build --config Release --target clean

# Reconfigure (after CMakeLists.txt changes)
cmake -B build -G "Visual Studio 17 2022" -A x64

# Verbose build
cmake --build build --config Release --verbose

# Install (if install() commands added)
cmake --install build --config Release
```

## Generator Options

```cmd
# Visual Studio 2022 (default on Windows)
cmake -B build -G "Visual Studio 17 2022" -A x64

# Ninja (faster, needs ninja installed)
cmake -B build -G Ninja

# NMake (legacy)
cmake -B build -G "NMake Makefiles"
```

## Adding Libraries

```cmake
# Static library
add_library(my_lib STATIC src/lib/mylib.cpp)

# Link to executable
target_link_libraries(food_delivery_lld PRIVATE my_lib)

# External library (e.g., fmt, spdlog)
find_package(fmt REQUIRED)
target_link_libraries(food_delivery_lld PRIVATE fmt::fmt)
```

## Adding Tests

```cmake
enable_testing()

add_executable(test_user test/UserTest.cpp src/model/User.cpp)
target_link_libraries(test_user PRIVATE gtest_main)
add_test(NAME UserTest COMMAND test_user)
```

## Project Structure Mapping

```
CMakeLists.txt
├── include/                    # Headers (auto-included via include_directories)
│   └── model/
│       ├── User.hpp
│       ├── Customer.hpp
│       └── Address.hpp
├── src/                        # Source files (listed in add_executable)
│   └── model/
│       ├── User.cpp
│       ├── Customer.cpp
│       └── Address.cpp
├── main.cpp                    # Entry point
└── build/                      # Generated (not in source control)
```

## Batch Scripts Integration

| Script | CMake Command |
|--------|---------------|
| `cmake_configure.bat` | `cmake -B build -G "Visual Studio 17 2022" -A x64` |
| `cmake_build.bat` | Configure + `cmake --build build --config Release` |
| `clean_build.bat` | `rmdir build` + Configure + Build |
| `run.bat` | `./build/Release/food_delivery_lld.exe` |

## Troubleshooting

| Issue | Solution |
|-------|----------|
| "No CMAKE_C_COMPILER" | Run inside VS Developer Command Prompt |
| New .cpp not compiled | Re-run `cmake_configure.bat` (if using GLOB) or add to CMakeLists.txt |
| Header not found | Check `include_directories(include)` and file exists in `include/` |
| Linker errors | Ensure all `.cpp` files listed in `add_executable` |

## Best Practices

1. **Explicit listing** for small/medium projects (current approach) - reliable, no re-configure needed
2. **GLOB_RECURSE** for large projects - convenient but requires re-configure
3. **One CMakeLists.txt** at root for simple projects
4. **Separate CMakeLists.txt** per subdirectory for modular projects
5. **Use target_include_directories** instead of global `include_directories` for larger projects