// La vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca
#include "View.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#pragma pop()
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>
#include <QPixmap>
#include <QIcon>
#include <QtGui>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QtGui>

using iter::range;
template <typename T>
QPushButton* view::ChessWindow::addSquare(int x, int y)
{
	auto square = new QPushButton(this);
	square->setFixedSize(80, 80);
	if constexpr (!is_same_v<T, decltype(nullptr)>)
	QObject::connect(square, &QPushButton::clicked, game, [this, x, y, square]() {selectedSquare(x, y, square);});
	//position_ = Position{ x,y };
	if ((x + y) % 2 == 0) {
		setStyleSheet("background-color:rgb(159,179,159)");
	}
	else {
		setStyleSheet("background-color:rgb(106,128,120)");
	}
	//QObject::connect(square, &QPushButton::clicked, this, [this, i, j, square]() {selectedSquare(i, j, square); });
	layout->addWidget(square, x, y);
	return square;
}

view::ChessWindow::ChessWindow(logic::Game* game, QWidget* parent) :
	QMainWindow(parent),
	game(game)
	//ui(new Ui::ChessBoard)
{
	// Si on objet n'a pas encore de parent on lui met "this" comme parent en attendant, si possible, pour s'assurer que tous les pointeurs sont gérés par un delete automatique en tout temps sans utiliser de unique_ptr.
	QIcon appIcon = QIcon("./img/appicon.png");
	setFixedSize(QSize(880, 1100));
	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);  // Donner un parent à un layout est comme un setLayout.

	// Version avec setProperty:
	{
		auto layout = new QGridLayout();
		layoutPrincipal->addLayout(layout);


		for (int i = 0 ; i < 8 ; i++) 
		{
			for (int j = 0 ; j < 8 ; j++) 
			{
				auto square = addSquare(i, j);
				//QObject::connect(this, &QPushButton::clicked, &game, [this]() {selected(this, position_); });
				//auto button = addSquare(i, j);
				// On donne un nom à la propriété, et on lui donne une valeur QVariant (comme dans les notes de cours) d'un type quelconque (doit enregistrer le type avec Q_DECLARE_METATYPE(LeType) si ce n'est pas un type déjà connu de Qt).
			}
			
		}

	QHBoxLayout* whitePieceLayout = new QHBoxLayout;
	QHBoxLayout* blackPieceLayout = new QHBoxLayout;

	auto whiteKnight = new QPushButton();
	whiteKnight->setIcon(wKnightIcon);
	whiteKnight->setIconSize(QSize(60,60));
	whiteKnight->setFixedSize(80,80);
	connect(whiteKnight, &QPushButton::clicked, this, [this, whiteKnight]() {pieceSelected(whiteKnight); });
	auto whiteRook = new QPushButton();
	//whiteRook->setText("White Rook");
	whiteRook->setIcon(wRookIcon);
	whiteRook->setIconSize(QSize(60,60));
	whiteRook->setFixedSize(80, 80);
	connect(whiteRook, &QPushButton::clicked, this, [this, whiteRook]() {pieceSelected(whiteRook); });
	auto whiteKing = new QPushButton();
	//whiteKing->setText("White King");
	whiteKing->setIcon(wKingIcon);
	whiteKing->setIconSize(QSize(60,60));
	whiteKing->setFixedSize(80, 80);
	connect(whiteKing, &QPushButton::clicked, this, [this, whiteKing]() {pieceSelected(whiteKing); });

	whitePieceLayout->addWidget(whiteKnight);
	whitePieceLayout->addWidget(whiteRook);
	whitePieceLayout->addWidget(whiteKing);

	auto blackKnight = new QPushButton();
	blackKnight ->setIcon(bKnightIcon);
	blackKnight ->setIconSize(QSize(60,60));
	blackKnight ->setFixedSize(80, 80);
	//blackBishop->setText("Black Bishop");
	connect(blackKnight, &QPushButton::clicked, this, [this, blackKnight]() {pieceSelected(blackKnight); });
	
	auto blackRook = new QPushButton();
	//blackRook->setText("Black Rook");
	blackRook->setIcon(bRookIcon);
	blackRook->setIconSize(QSize(60,60));
	blackRook->setFixedSize(80, 80);
	connect(blackRook, &QPushButton::clicked, this, [this, blackRook]() {pieceSelected(blackRook); });
	auto blackKing = new QPushButton();
	//blackKing->setText("Black Rook");
	blackKing->setIcon(bKingIcon);
	blackKing->setIconSize(QSize(60,60));
	blackKing->setFixedSize(80, 80);
	//blackKing->setText("Black King");
	connect(blackKing, &QPushButton::clicked, this, [this, blackKing]() {pieceSelected(blackKing); });

	blackPieceLayout->addWidget(blackKnight);
	blackPieceLayout->addWidget(blackRook);
	blackPieceLayout->addWidget(blackKing);

	layoutPrincipal->addLayout(layout);
	layoutPrincipal->addLayout(whitePieceLayout);
	layoutPrincipal->addLayout(blackPieceLayout);

	layoutPrincipal->setSpacing(5);
	
	widgetPrincipal->setLayout(layoutPrincipal);
	widgetPrincipal->setFixedSize(850, 950);

	//chessBoard[7][4] =  blackKing;
	//setCentralWidget(widgetPrincipal);
	//setWindowTitle("Echiquier");

	// On crée un bouton 'Exit'
	QAction* exit = new QAction(tr("E&xit"), this);
	// On connecte le clic sur ce bouton avec l'action de clore le programme
	connect(exit, SIGNAL(triggered()), this, SLOT(close()));

	// On crée un nouveau menu 'File'
	QMenu* menuMenu = menuBar()->addMenu(tr("&Menu"));
	// Dans lequel on ajoute notre bouton 'Exit'
	menuMenu->addAction(exit);
	}

	setCentralWidget(widgetPrincipal);
	setWindowTitle("let's play chess!");
}


Position view::ChessWindow::selectedSquare(int x_, int y_, QPushButton* button) {
	Position pos;
	pos.row = x_;
	pos.column = y_;
	
	std::cout << "clicked button at position (" << pos.row <<"," << pos.column << ")"<< std::endl;
	clickBoutonCase++;
	if (clickBoutonCase == 1 && clickBoutonPiece == 1) {
		button->setIcon(icone_);
		button->setIconSize(QSize(60,60));
		clickBoutonCase = 0;
		clickBoutonPiece = 0;
	}
	else if (clickBoutonCase == 1) {

		if (button->text() == "") {
			clickBoutonCase = 0;
		}
		else {
			icone_ = button->icon();
			previousClickedSquared = button;
		}
	}
	else if (clickBoutonCase == 2) {

		if (previousClickedSquared != button) {
			button->setIcon(icone_);
			previousClickedSquared->setIcon(QIcon());
		}

		clickBoutonCase = 0;
		previousClickedSquared = nullptr;
	}
	return pos;
}

void view::ChessWindow::pieceSelected(QPushButton* button) {
	clickBoutonPiece = 1;
	clickBoutonCase = 0;
	icone_ = button->icon();
	//return button;
}