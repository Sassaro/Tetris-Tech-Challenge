# CMakeList.txt : CMake project for Tetris, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Tetris "Tetris.cpp" "Tetris.h")

add_subdirectory("Domain")
add_subdirectory("Tests")

target_link_libraries(Tetris PRIVATE domain_library)
