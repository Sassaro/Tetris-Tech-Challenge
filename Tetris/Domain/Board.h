#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__

#include "ShapeGenerator.h"
#include "ScoreManager.h"
#include <Constants.h>

class Board {

private:
	ScoreManager scoreManager = ScoreManager();

protected:
	Board();

	static Board* boardInstance;

public:

	Board(Board& other) = delete;

	void operator=(const Board&) = delete;

	//TODO: MOVER A PRIVADO, ACCEDER POR METODO
	int boardMatrix[BOARD_HEIGHT][BOARD_WIDTH] = { 0 };

	bool isCollision();

	bool willCollision(std::shared_ptr<Shape> shape);

	void merge();

	void drawBoard();

	void clearScreen();

	void clearFilledLines();

	void deleteLine(int row);

	void dropBlocks(int row);

	bool isGameOver();

	static Board* GetInstance();

};

#endif // !__BOARD_H__
