# Food Delivery LLD - Build & Run Guide

## Prerequisites

- **Visual Studio 2022** (Community/Professional/Enterprise) with **Desktop development with C++** workload
- **Windows 10 SDK** (10.0.19041.0 or later)
- **CMake 3.16+** (included with Visual Studio 2022)

## Quick Start

### Option 1: Using Batch Scripts (Recommended)

```cmd
# Clean build (first time or after major changes)
clean_build.bat

# Regular build (incremental)
cmake_build.bat

# Run the executable
run.bat
```

### Option 2: Manual Commands (Visual Studio Developer Command Prompt)

Open **Visual Studio Developer Command Prompt** (or run `VsDevCmd.bat`):

```cmd
# 1. Configure CMake (run once, or after CMakeLists.txt changes)
cmake -B build -G "Visual Studio 17 2022" -A x64

# 2. Build in Release mode
cmake --build build --config Release

# 3. Run the executable
./build/Release/food_delivery_lld.exe
```

### Option 3: PowerShell One-Liner

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"; cmake -B build -G "Visual Studio 17 2022" -A x64; cmake --build build --config Release; ./build/Release/food_delivery_lld.exe
```

### Option 4: cmd.exe One-Liner

```cmd
call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" && cmake -B build -G "Visual Studio 17 2022" -A x64 && cmake --build build --config Release && ./build/Release/food_delivery_lld.exe
```

## Batch Scripts Reference

| Script | Purpose |
|--------|---------|
| `cmake_configure.bat` | Configure CMake only (run after CMakeLists.txt changes) |
| `cmake_build.bat` | Configure + Build in Release mode |
| `clean_build.bat` | Clean build directory + Configure + Build |
| `run.bat` | Run the built executable |

## Expected Output

```
User ID: 1
User Name: John Doe
User Email: john@gmail.com
User Phone Number: 123-456-7890
```

## Project Structure

```
Food_Delivery_LLD/
├── include/              # Header files
│   ├── model/
│   │   └── User.hpp
│   └── ...
├── src/                  # Source files
│   ├── model/
│   │   └── User.cpp
│   └── ...
├── tests/                # Unit tests
├── build/                # Build output (generated)
├── CMakeLists.txt        # CMake configuration
├── main.cpp              # Entry point
├── cmake_configure.bat   # Configure script
├── cmake_build.bat       # Build script
├── clean_build.bat       # Clean build script
├── run.bat               # Run script
└── README.md
```

## Troubleshooting

### "cmake not recognized"
Run commands inside **Visual Studio Developer Command Prompt** or call `VsDevCmd.bat` first.

### "No CMAKE_C_COMPILER found"
Ensure Visual Studio 2022 with C++ workload is installed. Run `VsDevCmd.bat` before cmake.

### "rc.exe not found" / "crtdbg.h not found"
Install **Windows 10 SDK** via Visual Studio Installer:
1. Open Visual Studio Installer
2. Modify → Individual Components → Windows 10 SDK (10.0.19041.0 or later)

### Build fails with syntax errors
Check that `src/model/User.cpp` and `include/model/User.hpp` are not corrupted (no batch commands mixed in).

## CMake Options

```cmd
# Debug build
cmake --build build --config Debug

# Specify different generator
cmake -B build -G "NMake Makefiles" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl

# Verbose output
cmake --build build --config Release --verbose
```

## Adding New Source Files

1. Add `.hpp` to `include/` (mirroring namespace structure)
2. Add `.cpp` to `src/` (mirroring namespace structure)
3. CMake uses `file(GLOB_RECURSE ...)` so new files are auto-detected
4. Re-run `cmake_configure.bat` or `clean_build.bat`

## Running Tests

```cmd
# Enable testing in CMake (already enabled)
# Build tests
cmake --build build --config Release --target RUN_TESTS

# Or run ctest directly
ctest --test-dir build --output-on-failure -C Release
```