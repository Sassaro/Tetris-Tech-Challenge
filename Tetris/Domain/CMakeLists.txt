# CMakeList.txt : CMake project for Tetris_Test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_library(domain_library

 "Shapes/SquareShape.cpp"
 "Shapes/SquareShape.h"
 "Shapes/StraightShape.h"
 "Shapes/StraightShape.cpp"
 "Shapes/TShape.h"
 "Shapes/TShape.cpp"
 "Shapes/LShape.h"
 "Shapes/LShape.cpp"
 "Shapes/Shape.cpp"
 "Shapes/Shape.h"
 "Shapes/SkewShape.h"
 "Shapes/SkewShape.cpp" "ShapeGenerator.h" "ShapeGenerator.cpp" "Board.cpp" "Board.h" "Constants.h" "ScoreManager.cpp" "ScoreManager.h" "Scenes/Scene.cpp" "Scenes/Scene.h" "Scenes/MainMenuScene.cpp" "Scenes/MainMenuScene.h" "Scenes/GameScene.cpp" "Scenes/GameScene.h" "Scenes/GameOverScene.cpp" "Scenes/GameOverScene.h")

# TODO: Add tests and install targets if needed.
target_include_directories(domain_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})