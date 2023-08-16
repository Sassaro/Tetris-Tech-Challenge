#include "GameScene.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "ShapeGenerator.h"
#include "GameOverScene.h"

GameScene::GameScene() {
	return;
}

GameScene::~GameScene() {
	return;
}

void GameScene::checkInput() {

    while (!Board::GetInstance()->isGameOver())
    {
        // Wait for single character 
        char input = getchar();

        if (input != ' ')
        {
            std::shared_ptr<Shape> currentShape = ShapeGenerator::GetInstance()->getCurrentShape();

            if (input == 'd')
            {
                currentShape->move(1, 0);
            }

            if (input == 'a')
            {
                currentShape->move(-1, 0);
            }

            if (input == 'w')
            {
                currentShape->rotateShape();
            }
        }
    }

    return;
}

void GameScene::runScene() {

    std::thread t1(&GameScene::checkInput,this);

    Board* boardSingleton = Board::GetInstance();
    
    while (!boardSingleton->isGameOver())
    {
        ShapeGenerator::GetInstance()->generateRandomShape();

        ShapeGenerator::GetInstance()->getCurrentShape()->resetShape();

        while (!boardSingleton->isCollision())
        {
            ShapeGenerator::GetInstance()->getCurrentShape()->move(0, -1);
            boardSingleton->drawBoard();

            // Simulate game loop with a small delay
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }

        boardSingleton->merge();
    }

    GameOverScene gameOverScene = GameOverScene();

    gameOverScene.startScene();

	return;
}