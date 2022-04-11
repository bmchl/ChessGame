﻿#include "Chess.hpp"
#include "Piece.hpp"
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

	King k(board, 'W');
	King K(board, 'B');

	Queen q(board, 'W');
	Queen Q(board, 'B');

	Bishop b1(board, 'W', 2);
	Bishop b2(board, 'W', 5);

	Bishop B1(board, 'B', 2);
	Bishop B2(board, 'B', 5);

	Knight n1(board, 'W', 1);
	Knight n2(board, 'W', 6);

	Knight N1(board, 'B', 1);
	Knight N2(board, 'B', 6);

	Rook r1(board, 'W', 0);
	Rook r2(board, 'W', 7);

	Rook R1(board, 'B', 0);
	Rook R2(board, 'B', 7);

	Pawn p1(board, 'W', 0);
	Pawn p2(board, 'W', 1);
	Pawn p3(board, 'W', 2);
	Pawn p4(board, 'W', 3);
	Pawn p5(board, 'W', 4);
	Pawn p6(board, 'W', 5);
	Pawn p7(board, 'W', 6);
	Pawn p8(board, 'W', 7);

	Pawn P1(board, 'B', 0);
	Pawn P2(board, 'B', 1);
	Pawn P3(board, 'B', 2);
	Pawn P4(board, 'B', 3);
	Pawn P5(board, 'B', 4);
	Pawn P6(board, 'B', 5);
	Pawn P7(board, 'B', 6);
	Pawn P8(board, 'B', 7);


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.squares[i][j]->currentPiece != nullptr)
			{
				cout << *(board.squares[i][j]->currentPiece);
			}
		}
	}

	//queen.setPosition(board.squares[0][7]);
	//cout << queen;
	//queen.setPosition(board.squares[0][3]);
	//cout << queen;
	//queen.setPosition(board.squares[7][7]);
	//cout << queen;
}
