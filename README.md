# C++ Playground

A clean, beginner-friendly C++17 collection of reusable programming exercises and console utilities.

## Features

- Prime number checker and generator
- Even and odd number lists
- Fibonacci sequence generator
- Factorial calculator
- Number and string palindrome checker
- Decimal to binary, octal, and hexadecimal conversion
- Random number generator
- Basic arithmetic calculator
- Input validation and menu-based console interface
- Reusable exercise functions separated from the application entry point

## Technologies

- C++17
- CMake 3.16+
- Standard C++ Library
- CTest

## Project Structure

```text
.
├── CMakeLists.txt
├── README.md
├── LICENSE
├── assets/
├── docs/
├── exercises/
├── include/playground/
├── src/
└── tests/
```

## Requirements

- A C++17-compatible compiler
- CMake 3.16 or newer

## Build and Run

```bash
cmake -S . -B build
cmake --build build
./build/playground
```

On Windows, run `build\playground.exe` or open the Visual Studio solution from CMake.

## Run Tests

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
ctest --test-dir build --output-on-failure
```

## Adding an Exercise

1. Declare reusable functions in `include/playground/exercises.hpp`.
2. Implement them in `src/exercises.cpp` or a dedicated source file.
3. Add menu logic to `src/main.cpp`.
4. Add unit tests to `tests/exercises_test.cpp`.

The exercise API is kept independent of console input and output, making functions easy to reuse in future interfaces.

## Roadmap

- [ ] Add more algorithms and data structures
- [ ] Add individual source modules for each exercise
- [ ] Expand test coverage
- [ ] Add benchmark examples
- [ ] Create a Qt 6 graphical interface
- [ ] Add OpenCV image loading and saving
- [ ] Add grayscale conversion, resizing, and edge detection
- [ ] Add basic computer vision experiments

## Future Qt and OpenCV Architecture

The project is organized as a small reusable library with a separate console application. Future work can retain `playground_lib` for algorithms and add GUI or image-processing targets without mixing business logic into UI code.

Qt 6 may replace or complement the console interface. OpenCV integration may add optional image modules while keeping the core C++ exercises independent of third-party libraries.
