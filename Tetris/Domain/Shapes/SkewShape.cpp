#include "SkewShape.h"

SkewShape::SkewShape() {

    this->shape = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
    };

    return;
}

SkewShape::~SkewShape() {
    return;
}