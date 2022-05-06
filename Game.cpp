#include "Game.hpp"

void Game:: reset()
{
	k = nullptr;
	K = nullptr;
	pieces.clear();
	board = Board();
}

bool Game:: isInCheck()
{
	for (auto pair : pieces)
	{
		if ((board.isValidMove(*board.squares[pair.second.row][pair.second.column], *board.squares[pieces[k].row][pieces[k].column])) || (board.isValidMove(*board.squares[pair.second.row][pair.second.column], *board.squares[pieces[K].row][pieces[K].column])))
		{
			return true;
		}
	}
	return false;
}
bool Game:: isOver()
{
	if (k->isDead)
	{
		winner = "Black";
		return true;
	}
	else if (K->isDead)
	{
		winner = "White";
		return true;
	}
	return false;
}
bool Game::isImpossibleMove(Position* currentPosition, Position* newPosition)
{
	if (board.squares[currentPosition->row][currentPosition->column]->currentPiece->color_ != turn)
	{
		return true;
	}
	else
	{
		if (not board.isValidMove(*board.squares[currentPosition->row][currentPosition->column], *board.squares[newPosition->row][newPosition->column]))
		{
			return true;
		}
	}
	return false;
}
void Game::makeMove(Position* currentPosition, Position* newPosition)
{
	board.setPosition(*board.squares[currentPosition->row][currentPosition->column], *board.squares[newPosition->row][newPosition->column]);
	//::cout << "attempting move from position (" << currentPosition->row << "," << currentPosition->column << ") to (" << newPosition->row << "," << newPosition->column << ")" << std::endl;
	/*std::cout << "verifying correct move" << std::endl;
	std::cout << "my color is: " << turn << std::endl;
	std::cout << "the piece's color is: " << board.squares[currentPosition->row][currentPosition->column]->currentPiece->color_ << std::endl;*/
	//if (board.squares[currentPosition->row][currentPosition->column]->currentPiece->color_ == turn)
	//{
	//	//std::cout << "right color" << std::endl;
	//	
	//}
	//else
	//{
	//	//std::cout << "wrong color" << std::endl;
	//}
}
void Game::initializePieces()
{
	k = std::make_shared<King>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 0,3 }));
	board.placePiece(k, pieces[k]);
	
	K = std::make_shared<King>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 7,3 }));
	board.placePiece(K, pieces[K]);
}
void Game::setOption1()
{
	k = std::make_shared<King>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 3,2 }));
	board.placePiece(k, pieces[k]);
	
	K = std::make_shared<King>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 3,0 }));
	board.placePiece(K, pieces[K]);
	
	auto N = std::make_shared<Knight>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 1,0 }));
	board.placePiece(N, pieces[N]);
	std::cout << "created knight" << std::endl;
	
	auto r = std::make_shared<Rook>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{0,1}));
	board.placePiece(r, pieces[r]);
	std::cout << "created rook" << std::endl;
}
void Game::setOption2()
{
	k = std::make_shared<King>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 2,4 }));
	board.placePiece(k, pieces[k]);
	
	K = std::make_shared<King>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 5,7 }));
	board.placePiece(K, pieces[K]);
	
	auto N = std::make_shared<Knight>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 2,1 }));
	board.placePiece(N, pieces[N]);
	std::cout << "created knight" << std::endl;
	
	auto r = std::make_shared<Rook>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{ 1,5 }));
	board.placePiece(r, pieces[r]);
	std::cout << "created rook" << std::endl;
}
void Game::setOption3()
{
	k = std::make_shared<King>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 4,7 }));
	board.placePiece(k, pieces[k]);
	
	K = std::make_shared<King>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 5,5 }));
	board.placePiece(K, pieces[K]);
	
	auto N = std::make_shared<Knight>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 6,4 }));
	board.placePiece(N, pieces[N]);
	std::cout << "created knight" << std::endl;
	
	auto r = std::make_shared<Rook>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{ 0,4 }));
	board.placePiece(r, pieces[r]);
	std::cout << "created rook" << std::endl;
	
	auto R = std::make_shared<Rook>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(R, Position{ 7,6 }));
	board.placePiece(R, pieces[R]);
	std::cout << "created rook" << std::endl;
}
void Game::setOption4()
{
	k = std::make_shared<King>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(k, Position{ 4,3 }));
	board.placePiece(k, pieces[k]);
	
	K = std::make_shared<King>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(K, Position{ 2,3 }));
	board.placePiece(K, pieces[K]);
	
	auto N = std::make_shared<Knight>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(N, Position{ 1,3 }));
	board.placePiece(N, pieces[N]);
	std::cout << "created knight" << std::endl;
	
	auto r = std::make_shared<Rook>('W');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(r, Position{ 6,1 }));
	board.placePiece(r, pieces[r]);
	std::cout << "created rook" << std::endl;
	
	auto R = std::make_shared<Rook>('B');
	pieces.insert(std::pair<std::shared_ptr<Piece>, Position>(R, Position{ 1,0 }));
	board.placePiece(R, pieces[R]);
	std::cout << "created rook" << std::endl;
}
