#include "Shape.h"
#include <iostream>
#include <algorithm>
#include "Board.h"

Shape::Shape() {
	return;
}

void Shape::move(int dx, int dy) {

	Board* board = Board::GetInstance();
	//makes a shallow copy of the shape and moves it in the selected direction
	Shape shapeCopy = Shape(*this);

	shapeCopy.xPosition += dx;

	if (this->xPosition + this->getLeftLimit() + dx < 0 ||
	    this->xPosition + this->getShapeWidth() + dx > BOARD_WIDTH - 1 ||
		//checks if the copy will colide with the other shapes, if it does it won't move
		board->willCollision(std::make_shared<Shape>(shapeCopy))) {
	}
	else {
		this->xPosition += dx;
	}

	this->yPosition += dy;

	return;
}

void Shape::resetShape() {

	this->xPosition = BOARD_WIDTH / 2 - 2;
	this->yPosition = BOARD_HEIGHT - 1;

}

int Shape::getXPosition() {

	return this->xPosition;
}

int Shape::getYPosition() {

	return this->yPosition;
}

int Shape::getShapeWidth() {

	std::vector<std::vector<int>> shape = this->getShape();

	int width = 0;

	for (int row = 0; row < shape.size(); ++row)
	{
		for (int column = 0; column < shape.size(); ++column) {

			if (shape[row][column] == 1) {
				if (width < column) {
					width = column;
				}
			}
		}
	}
	return width;
}

void Shape::rotateShape() {

	Board* board = Board::GetInstance();
	Shape shapeCopy = Shape(*this);
	shapeCopy.turnShape();

	if (board->willCollision(std::make_shared<Shape>(shapeCopy))) {
	}
	else {
		this->turnShape();
	}

	return;
}

void Shape::turnShape() {

	for (int i = 0; i < shape.size(); ++i) {
		for (int j = i; j < shape.size(); ++j) {
			std::swap(shape[i][j], shape[j][i]);
		}
	}

	for (int i = 0; i < shape.size(); ++i) {
		for (int j = 0; j < shape.size() / 2; ++j) {
			std::swap(shape[i][j], shape[i][shape.size() - j - 1]);
		}
	}
	return;
}

std::vector<std::vector<int>> Shape::getShape() {

	return this->shape;
}

int Shape::getLeftLimit() {
	
	for (int i = 0; i != shape.size(); i++ ) {
	
		for (int j = 0; j != shape.size(); j++) {
			
			if (shape[i][j] == 1) {
				auto aux = j;
				return j;
			}
		}
	}
	
	return 0;
}

int Shape::getRightLimit() {

	int width = 0;

	for (int row = 0; row < shape.size(); ++row)
	{
		for (int column = 0; column < shape.size(); ++column) {

			if (this->shape[row][column] == 1) {
				if (width < column) {
					width = column;
				}
			}
		}
	}
	return width;
}