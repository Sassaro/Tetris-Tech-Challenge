
#include "ShapeGenerator.h"

ShapeGenerator* ShapeGenerator::shapeGeneratorInstance = nullptr;;

ShapeGenerator::ShapeGenerator() {

	return;
}

void ShapeGenerator::generateRandomShape() {

	int randomIndex = rand() % shapeList.size();

	this->currentShape = this->shapeList[randomIndex];

	return;

}

std::shared_ptr<Shape> ShapeGenerator::getCurrentShape() {

	return this->currentShape;

}

ShapeGenerator* ShapeGenerator::GetInstance()
{
    if (shapeGeneratorInstance == nullptr) {
        shapeGeneratorInstance = new ShapeGenerator();
    }
    return shapeGeneratorInstance;
}