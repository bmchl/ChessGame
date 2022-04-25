//Projet final INF1015
//Michael Banna (2147128) & Nour Zahreddine (2167661)

#include "Game.h"
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
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette ent�te si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par d�faut.

	// cdbg.setTee(&clog);  // D�commenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du d�bogueur.

	//bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un r�sultat de test.
#endif
//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main apr�s l'appel � cette fonction puisqu'il ex�cute uniquement les tests Google Test dans l'appel ci-dessus.
}

using namespace std;
using namespace iter;
using namespace gsl;

int main(int argc, char* argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	//QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);
	Game game;
	game.play();

	//D�COMMENTER LES LIGNES SUIVANTES POUR TESTER LE FONCTIONNEMENT SANS PASSER PAR LES INPUTS
	//p2.makeMove(board.squares[0][3], board.squares[0][4]);
	//p1.makeMove(board.squares[0][4], board.squares[0][5]);
	//p1.makeMove(board.squares[4][6], board.squares[0][6]);
	//p2.makeMove(board.squares[3][5], board.squares[1][6]);
	//p2.makeMove(board.squares[1][6], board.squares[2][4]);
	//p1.makeMove(board.squares[0][4], board.squares[0][6]);

	return 0;
}

