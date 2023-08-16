#include "TShape.h"

TShape::TShape() {

	this->shape = {
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
    };

	return;
}

TShape::~TShape() {
	return;
}