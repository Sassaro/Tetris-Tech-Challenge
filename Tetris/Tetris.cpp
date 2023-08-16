#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "ShapeGenerator.h"
#include "Board.h"
#include "Scenes/MainMenuScene.h"

int main()
{
    MainMenuScene scene = MainMenuScene();

    scene.runScene();
    return 0;
}