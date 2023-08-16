
#include "Board.h"

Board* Board::boardInstance = nullptr;;

Board::Board() {
	return;
}

bool Board::isGameOver() {

    auto auxGameOver = false;

    for (int j = 0; j < BOARD_WIDTH; ++j)
    {
        auxGameOver = auxGameOver || this->boardMatrix[BOARD_HEIGHT - 1][j] == 1;
    }

    return auxGameOver;
}

bool Board::isCollision() {
    std::shared_ptr<Shape> currentShape = ShapeGenerator::GetInstance()->getCurrentShape();

    return this->willCollision(currentShape);
}

bool Board::willCollision(std::shared_ptr<Shape> shape) {

    int shapeSize = shape->getShape().size();

    for (int i = 0; i < shapeSize; ++i)
    {
        for (int j = 0; j < shapeSize; ++j)
        {
            if (shape->getShape()[i][j] && (shape->getYPosition() - i == 0) || shape->getShape()[i][j] && boardMatrix[shape->getYPosition() - i - 1][shape->getXPosition() + j])
            {
                return true;
            }
        }
    }

    return false;
}

void Board::merge() {
    std::shared_ptr<Shape> currentShape = ShapeGenerator::GetInstance()->getCurrentShape();

    int shapeSize = currentShape->getShape().size();

    for (int i = 0; i < shapeSize; ++i)
    {
        for (int j = 0; j < shapeSize; ++j)
        {
            if (ShapeGenerator::GetInstance()->getCurrentShape()->getShape()[i][j])
            {
                boardMatrix[currentShape->getYPosition() - i][currentShape->getXPosition() + j] = 1;
            }
        }
    }

    //revisa si hay lineas a borrar, las borra y calcula el puntaje.
    clearFilledLines();
}

void Board::clearFilledLines() {

    int linesCompleted = 0;

    for (int i = BOARD_HEIGHT - 1; i >= 0; --i)
    {
        bool isFilled = true;

        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            if (boardMatrix[i][j] == 0) {
                isFilled = false;
            }
        }

        if (isFilled) {
            this->deleteLine(i);
            linesCompleted++;
        }
    }

    this->scoreManager.calculateScore(linesCompleted);

    return;
}

void Board::dropBlocks(int row) {

    auto aux = BOARD_HEIGHT - row;
    auto aux2 = row;

    for (int i = row ; i < BOARD_HEIGHT; i++) {
    
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            if (boardMatrix[i][j] == 1) {
                boardMatrix[i][j] = 0;
                boardMatrix[i - 1][j] = 1;
            }
        }
    }
}

void Board::deleteLine(int row) {

    for (int j = 0; j < BOARD_WIDTH; ++j)
    {
        boardMatrix[row][j] = 0;
    }
    this->dropBlocks(row);
}

void Board::drawBoard() {
    std::shared_ptr<Shape> currentShape = ShapeGenerator::GetInstance()->getCurrentShape();
    clearScreen();
    for (int i = BOARD_HEIGHT - 1; i >= 0; --i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
        {
            if (i <= currentShape->getYPosition() && (currentShape->getYPosition() - 4) < i && j >= currentShape->getXPosition() && (currentShape->getXPosition() + 4) > j && currentShape->getShape()[currentShape->getYPosition() - i][j - currentShape->getXPosition()] != 0)
            {
                std::cout << "#";
            }
            else
            {
                if (boardMatrix[i][j] == 0)
                {
                    std::cout << ".";
                }
                else
                {
                    std::cout << "#";
                }
            }
        }
        std::cout << "\n";
    }
    this->scoreManager.printScore();
}

void Board::clearScreen() {
    system("cls");
}

Board* Board::GetInstance()
{
    if (boardInstance == nullptr) {
        boardInstance = new Board();
    }
    return boardInstance;
}