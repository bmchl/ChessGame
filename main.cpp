#include "Chess.hpp"
//#include "Piece.hpp"
//#include "Player.hpp"
//#include "CalcWindow.hpp"

//#include <QApplication>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <sstream>
#include <forward_list>
#include <numeric>
#include "cppitertools/range.hpp"
#include "cppitertools/enumerate.hpp"
#include "gsl/span"
#include <set>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	//bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

using namespace std;
using namespace iter;
using namespace gsl;

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	//QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	//CalcWindow calcWindow;
	//calcWindow.show();
	//return app.exec();
	Board board; 

	King k(board.squares[0][4], 'W');
	King K(board.squares[0][3], 'B');

	Rook r(board.squares[4][6], 'W');
	Knight N(board.squares[3][5], 'B');

	Player p1(board, 'W');
	Player p2(board, 'B');

	bool gameOver = false;
	char turn = 'B';

	int currentRow = 0;
	int currentColumn = 0;
	int newRow = 0;
	int newColumn = 0;

	cout << "game start" << endl;
	cout << "here are the current pieces on the board:" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.squares[i][j].currentPiece != nullptr)
			{
				cout << board.squares[i][j];
			}
		}
	}
	//DÉCOMMENTER LES LIGNES SUIVANTES POUR TESTER LE DÉROULEMENT D'UN JEU
	while (!gameOver)
	{
		if ((k.isDead) || (K.isDead))
		{
			gameOver = true;
			break;
		}
		if (turn == 'W') { turn = 'B'; }
		else if (turn == 'B') { turn = 'W'; }
		cout << "current turn: " << turn << endl;
		if (turn == 'W') 
		{ 
			cout << "player 1: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n"; 
			cin >> currentRow;
			cin >> currentColumn;
			cout << "player 1: pick a destination location\n";
			cin >> newRow;
			cin >> newColumn;
			p1.makeMove(board.squares[currentRow][currentColumn], board.squares[newRow][newColumn]);
		}
		else if (turn == 'B')
		{
			cout << "player 2: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n";
			cin >> currentRow;
			cin >> currentColumn;
			cout << "player 2: pick a destination location\n";
			cin >> newRow;
			cin >> newColumn;
			p2.makeMove(board.squares[currentRow][currentColumn], board.squares[newRow][newColumn]);
		}
	}
	cout << "game over";

	//DÉCOMMENTER LES LIGNES SUIVANTES POUR TESTER LE FONCTIONNEMENT SANS PASSER PAR LES INPUTS
	//p2.makeMove(board.squares[0][3], board.squares[0][4]);
	//p1.makeMove(board.squares[0][4], board.squares[0][5]);
	//p1.makeMove(board.squares[4][6], board.squares[0][6]);
	//p2.makeMove(board.squares[3][5], board.squares[1][6]);
	//p2.makeMove(board.squares[1][6], board.squares[2][4]);
	//p1.makeMove(board.squares[0][4], board.squares[0][6]);

	return 0;
}
   
