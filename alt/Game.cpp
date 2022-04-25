#include "Game.h"

Game::Game()
{
	board_ = Board();
	k = King(board_.squares[0][4], 'W');
	K = King(board_.squares[0][3], 'B');
}
void Game::play()
{
	using namespace std;
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
					if (board_.squares[i][j].currentPiece != nullptr)
						{
							cout << board_.squares[i][j];
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
						p1_.makeMove(board_.squares[currentRow][currentColumn], board_.squares[newRow][newColumn]);
				}
				else if (turn == 'B')
				{
						cout << "player 2: your turn. \nselect a piece on the board to move, one coordinate at a time \nexample, to access the piece at (3,0): \n 3 \n 0\n\n";
						cin >> currentRow;
						cin >> currentColumn;
						cout << "player 2: pick a destination location\n";
						cin >> newRow;
						cin >> newColumn;
						p2_.makeMove(board_.squares[currentRow][currentColumn], board_.squares[newRow][newColumn]);
				}
		}
		cout << "game over";
}