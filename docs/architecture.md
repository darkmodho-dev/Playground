# Future architecture notes

## Exercise modules

The reusable exercise API is exposed through `include/playground/exercises.hpp` and implemented in `src/exercises.cpp`. Console input and output are kept in `src/main.cpp`.

## Qt 6 integration

A future Qt application can link against `playground_lib` and call the namespace functions without replacing or duplicating exercise logic. UI-specific code should remain in a separate Qt target.

## OpenCV integration

Image functionality should use optional targets or components rather than making OpenCV a requirement of the console application. Suggested future modules:

- `image_io` for loading and saving images
- `image_processing` for grayscale conversion and resizing
- `image_analysis` for edge detection and computer vision experiments
