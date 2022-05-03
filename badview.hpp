#pragma once
// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#pragma pop()

#include "Position.hpp"
#include "Chess.hpp"

namespace view {
	//template <typename T>
	/*class ChessSquare : public QPushButton {
		Q_OBJECT
	public:
		ChessSquare(int x, int y): QPushButton(this)
		{
			setFixedSize(80, 80);
			position_ = Position{ x,y };
			if ((x + y) % 2 == 0) {
				setStyleSheet("background-color:rgb(159,179,159)");

			}
			else {
				setStyleSheet("background-color:rgb(106,128,120)");
			}
		};
		~ChessSquare() override = default;

	public slots:
		void selected(ChessSquare*, Position&)
		{

		};
	private:
		Position position_;
		QIcon icon_;
	};*/
	class ChessWindow : public QMainWindow {
	Q_OBJECT

public:
	ChessWindow(logic::Game* game, QWidget* parent = nullptr);
	~ChessWindow() override = default;

public slots:
	Position selectedSquare(int x, int y, QPushButton* button);
	void pieceSelected(QPushButton* button);

private:
	template <typename T = decltype(nullptr)>
	QPushButton* addSquare(int x, int y);
	QWidget* gridLayoutWidget;
	QPushButton* previousClickedSquared = nullptr;
	QIcon icone_;
	int clickBoutonPiece = 0;
	int clickBoutonCase = 0;
	
	QString label;

	const QIcon wKingIcon = QIcon("./img/wking.png");
	const QIcon bKingIcon = QIcon("./img/bking.png");

	const QIcon wRookIcon = QIcon("./img/wrook.png");
	const QIcon bRookIcon = QIcon("./img/brook.png");

	const QIcon wKnightIcon = QIcon("./img/wknight.png");
	const QIcon bKnightIcon = QIcon("./img/bknight.png");

	logic::Game* game; // le modele
};

}
