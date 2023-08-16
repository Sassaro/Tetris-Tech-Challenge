#include "ScoreManager.h"
#include <iostream>

ScoreManager::ScoreManager() {
	return;
}

ScoreManager::~ScoreManager() {
	return;
}

int ScoreManager::calculateScore(int linesCompleted) {
    switch (linesCompleted)
    {
    case 1:
        this->score += 10;
        break;
    case 2:
        this->score += 25;
        break;
    case 3:
        this->score += 40;
        break;
    case 4:
        this->score += 100;
        break;
    default:
        return 0;
        break;
    }
}

void ScoreManager::printScore() {
    std::cout << "Score: " << score << std::endl;
}

int ScoreManager::getScore() {
    return this->score;
}