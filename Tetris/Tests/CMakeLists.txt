# CMakeList.txt : CMake project for Tetris_Test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(unitTests "Tests.cpp")

target_link_libraries(unitTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(unitTests PRIVATE domain_library)