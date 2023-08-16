#pragma once
#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "vector"
#include "Constants.h"

class Shape {

private:

	void turnShape();

protected:
	std::vector<std::vector<int>> shape = {
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1}
		};
	int xPosition = BOARD_WIDTH / 2 - 2;
	int yPosition = BOARD_HEIGHT - 1;

public:

	Shape();

	Shape(const Shape& other) {

		this->shape = other.shape;
		this->xPosition = other.xPosition;
		this->yPosition = other.yPosition;
	}

	virtual ~Shape() = default;

	void move(int dx, int dy);

	void rotateShape();

	void resetShape();

	int getXPosition();

	int getYPosition();

	int getShapeWidth();

	int getLeftLimit();

	int getRightLimit();

	std::vector<std::vector<int>> getShape();
};

#endif // ! __SHAPE_H__

