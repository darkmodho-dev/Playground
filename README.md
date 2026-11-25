# Playground

A personal C++ learning space. Each exercise has its own folder so you can write, compile, and upload your own solution without starter implementations getting in the way.

## Exercise folders

All practice work goes under [`playground/`](playground/):

- `prime-number-checker/`
- `prime-numbers-generator/`
- `even-numbers/`
- `odd-numbers/`
- `fibonacci-sequence/`
- `factorial-calculator/`
- `palindrome-checker/`
- `number-converter/`
- `random-number-generator/`
- `basic-calculator/`

Each folder contains a short README. Add your own `.cpp` file there, for example `playground/prime-number-checker/main.cpp`. You can add a separate header if your solution needs one.

## Compile an exercise

With a C++17 compiler installed, compile a single exercise from the repository root. For example:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic playground/prime-number-checker/main.cpp -o prime-checker
./prime-checker
```

On Windows, the output executable may be named `prime-checker.exe`.

## Suggested workflow

1. Choose an exercise folder.
2. Create your own `.cpp` file in that folder.
3. Build and test it.
4. Commit and push your work when you are ready.

No exercise solutions are included—the goal is for you to practice and write them yourself. The `docs/` folder has notes about possible future Qt 6 and OpenCV additions.

## Future ideas

- Add more independent C++ exercises and algorithms.
- Optionally add a Qt 6 interface in a separate application folder.
- Explore OpenCV in a separate image-processing module for loading/saving images, grayscale conversion, resizing, edge detection, and computer vision experiments.

The future Qt and OpenCV work is not implemented yet; keep those dependencies optional so simple exercises remain easy to build.
