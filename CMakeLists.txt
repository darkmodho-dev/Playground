cmake_minimum_required(VERSION 3.16)

project(Playground VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(playground_lib
    src/exercises.cpp
)

target_include_directories(playground_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(playground_lib PUBLIC cxx_std_17)

add_executable(playground src/main.cpp)
target_link_libraries(playground PRIVATE playground_lib)

include(CTest)
if(BUILD_TESTING)
    add_executable(playground_tests tests/exercises_test.cpp)
    target_link_libraries(playground_tests PRIVATE playground_lib)
    add_test(NAME playground_tests COMMAND playground_tests)
endif()
