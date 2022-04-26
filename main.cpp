//Projet final INF1015
//Michael Banna (2147128) & Nour Zahreddine (2167661)

#include "Chess.hpp"
//#include "Piece.hpp"
//#include "Player.hpp"
#include "View.hpp"

#include <QApplication>
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
using namespace logic;
using namespace view;



int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	Board board; 

	King k(*board.squares[0][4], 'W');
	cout << *board.squares[0][4];
	cout << "the current number of instances of king is: " << k.getCount() << endl;
	King K(*board.squares[0][3], 'B');
	cout << *board.squares[0][3];
	cout << "the current number of instances of king is: " << k.getCount() << endl;

	/*cout << "performing temporary move on (0,3)" << endl;
	TemporaryPiece* tempKing = new TemporaryPiece(K, *board.squares[0][3]);
	cout << "the current number of instances of king is: " << k.getCount() << endl;
	cout << *board.squares[0][3];
	cout << *board.squares[1][3];
	cout << "deleting temporary piece instance" << endl;
	delete tempKing;
	cout << "the current number of instances of king is: " << k.getCount() << endl;
	cout << *board.squares[0][3];
	cout << *board.squares[1][3];
	
	cout << "new king instance is now" << endl;
	King k3(*board.squares[1][3], 'W');
	cout << "the current number of instances of king is: " << k.getCount() << endl;
	cout << *board.squares[1][3];*/

	try 
	{
		King K4(*board.squares[0][5], 'B');
		cout << *board.squares[0][5];
	}
	catch (KingInstanceException& e)
	{
		cout << e.what();
	}
	cout << *board.squares[0][5];
	cout << k.getCount() << endl;

	Rook r(*board.squares[4][6], 'W');
	Knight N(*board.squares[3][5], 'B');

	Player p1(board, 'W');
	Player p2(board, 'B');

	//DÉCOMMENTER LES LIGNES SUIVANTES POUR TESTER LE FONCTIONNEMENT SANS PASSER PAR LES INPUTS
	//p2.makeMove(*board.squares[0][3], *board.squares[0][4]);
	//cout << *board.squares[0][4] << endl;
	//p1.makeMove(board.squares[0][4], board.squares[0][5]);
	//p1.makeMove(board.squares[4][6], board.squares[0][6]);
	//p2.makeMove(board.squares[3][5], board.squares[1][6]);
	//p2.makeMove(board.squares[1][6], board.squares[2][4]);
	//p1.makeMove(board.squares[0][4], board.squares[0][6]);

	Ui_ChessWindow chessWindow;
	chessWindow.show();
	return app.exec();

	return 0;
}
   
