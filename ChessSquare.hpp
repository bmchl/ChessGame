#pragma once
#include <QtWidgets/QPushButton>
#include "Position.hpp"
namespace view
{
    class ChessSquare : public QPushButton
    {
    public:
        ChessSquare(int x, int y, QWidget* parent = nullptr) : QPushButton(parent)
        {
            position = new Position{ x,y };
        };
        Position* position;

    };
}