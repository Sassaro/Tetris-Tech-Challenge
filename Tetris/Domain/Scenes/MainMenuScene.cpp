#include "MainMenuScene.h"
#include <iostream>
#include "GameScene.h"

MainMenuScene::MainMenuScene() {
	return;
}

MainMenuScene::~MainMenuScene() {
	return;
}

void MainMenuScene::runScene() {

	std::cout << "				 /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$  /$$$$$$  /$$$$$$ \n";
	std::cout << "				|__  $$__/| $$_____/|__  $$__/| $$__  $$|_  $$_/ /$$__  $$\n";
	std::cout << "				   | $$   | $$         | $$   | $$  | $$  | $$  | $$  |__/\n";
	std::cout << "				   | $$   | $$$$$      | $$   | $$$$$$$/  | $$  |  $$$$$$ \n";
	std::cout << "				   | $$   | $$__/      | $$   | $$__  $$  | $$   |____  $$\n";
	std::cout << "				   | $$   | $$         | $$   | $$  | $$  | $$   /$$  | $$\n";
	std::cout << "				   | $$   | $$$$$$$$   | $$   | $$  | $$ /$$$$$$|  $$$$$$/\n";
	std::cout << "				   |__/   |________/   |__/   |__/  |__/|______/ |______/ \n \n \n";

	std::cout << "Controls:\n";
	std::cout << "Press A followed by Enter to move the block to the Left\n";
	std::cout << "Press D followed by Enter to move the block to the Right\n";
	std::cout << "Press W followed by Enter to rotate the block\n\n";

	std::cout << "To Start the game Press 0 and Enter\n\n";

	this->checkInput();

	return;
}

void MainMenuScene::checkInput() {

	GameScene gameScene = GameScene();

	char input;

	do {
		input = getchar();

		if (input == '0') {
			gameScene.startScene();
		}
		//just to clear the screen in case the user doesn't press 0
		this->startScene();
	} while (input != '0');
	
	return;
}