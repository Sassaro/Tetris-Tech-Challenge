#pragma once
#ifndef __SHAPE_GENERATOR_H__
#define __SHAPE_GENERATOR_H__

#include "./Shapes/SquareShape.h"
#include "./Shapes/StraightShape.h"
#include "./Shapes/TShape.h"
#include "./Shapes/SkewShape.h"
#include "./Shapes/LShape.h"
#include "vector"
#include <iostream>
#include <mutex>

class ShapeGenerator {

private:

	std::vector<std::shared_ptr<Shape>> shapeList = {
		std::make_shared<SkewShape>(SkewShape()),
		std::make_shared<LShape>(LShape()),
		std::make_shared<StraightShape>(StraightShape()),
		std::make_shared<TShape>(TShape()),
		std::make_shared<SquareShape>(SquareShape()) 
	};

	std::shared_ptr<Shape> currentShape;

protected:
	ShapeGenerator();

	static ShapeGenerator* shapeGeneratorInstance;

public:

	ShapeGenerator(ShapeGenerator& other) = delete;

	void operator=(const ShapeGenerator&) = delete;

	static ShapeGenerator* GetInstance();

	void generateRandomShape();

	std::shared_ptr<Shape> getCurrentShape();
};

#endif // !__SHAPE_GENERATOR_H__
