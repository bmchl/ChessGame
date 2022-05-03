//TD6 INF 1015
//Michael Banna (2147128) & Nour Zahreddine (2167661)
//Le code principal qui contient les démonstrations des implémentations des points 2 et 3 du travail pratique.
#include "Chess.hpp"
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

	//Game game;
	//game.play();
	//Board board; 

	//King k('W');
	//board.placePiece(make_shared<King>(k), Position{ 0,4 });
	//cout << *board.squares[0][4];
	//cout << "the current number of instances of king is: " << k.getCount() << endl;
	//King K('B');
	//board.placePiece(make_shared<King>(K), Position{ 0,3 });
	//cout << *board.squares[0][3];
	//cout << "the current number of instances of king is: " << k.getCount() << endl;

	//cout << "\n---------------------------------------------" << endl;
	//cout << "3. RAII d'une pièce temporaire\n" << endl;

	//cout << "instanciating RAII" << endl;
	//TemporaryPiece* tempKing = new TemporaryPiece(K, *board.squares[0][3]);
	//cout << "the current number of instances of king is: " << k.getCount() << endl; 
	//// On est encore à 2 instances car la classe prend l'objet par référence.
	//cout << *board.squares[0][3];
	//cout << "deleting temporary piece instance" << endl;
	//delete tempKing;
	//cout << "the current number of instances of king is: " << k.getCount() << endl;
	//// On revient à 1 instance car l'implémentation RAII appelle le destructeur de l'objet.
	//cout << *board.squares[0][3];


	//cout << "\n---------------------------------------------" << endl;
	//cout << "2. Compteur d'instances et exceptions\n" << endl;
	//King k3(*board.squares[1][3], 'W');
	//cout << "the current number of instances of king is: " << k.getCount() << endl;
	//// On initialise un nouvel objet pour forcer le programme à rencontrer l'exception.
	//cout << *board.squares[1][3];
	//try 
	//{
	//	King K4(*board.squares[0][5], 'B');
	//	cout << *board.squares[0][5];
	//}
	//catch (KingInstanceException& e)
	//{
	//	cout << "exception thrown: " << e.what();
	//}
	//cout << *board.squares[0][5];
	//cout << "the current number of instances of king is: " << k.getCount() << endl;
	//// On retrouve nos 2 instances de King. Ce code s'execute malgré le fait qu'on rencontre une exception.
	Game* game = new Game;
	ChessWindow chessWindow(game);
	chessWindow.show();
	return app.exec();
	//delete game;
	return 0;
}
   
