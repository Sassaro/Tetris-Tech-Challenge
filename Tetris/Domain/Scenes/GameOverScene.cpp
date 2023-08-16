
#include "GameOverScene.h"
#include <iostream>

GameOverScene::GameOverScene() {
	return;
}

GameOverScene::~GameOverScene() {
	return;
}

void GameOverScene::checkInput() {

	char input = getchar();
	return;
}

void GameOverScene::runScene() {

	std::cout << "  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$ \n";
	std::cout << " /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$\n";
	std::cout << "| $$  |__/| $$  | $$| $$$$  /$$$$| $$            | $$  | $$| $$   | $$| $$      | $$  | $$\n";
	std::cout << "| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/\n";
	std::cout << "| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$ |  $$ $$/ | $$__/   | $$__  $$\n";
	std::cout << "| $$  | $$| $$  | $$| $$|  $ | $$| $$            | $$  | $$  |  $$$/  | $$      | $$  | $$\n";
	std::cout << "|  $$$$$$/| $$  | $$| $$ |/  | $$| $$$$$$$$      |  $$$$$$/   |  $/   | $$$$$$$$| $$  | $$\n";
	std::cout << " |______/ |__/  |__/|__/     |__/|________/       |______/     |_/    |________/|__/  |__\n";

	std::cout << "Press Enter to leave the Game\n\n";

	this->checkInput();

	return;
}