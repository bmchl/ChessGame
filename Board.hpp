//#pragma once
//
//#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
//#include <QObject>
//#pragma pop()
//#include <functional>
//#include "Chess.hpp"
//
//using namespace std;
//
//class Board : public QObject
//{
//	Q_OBJECT
//public:
//	int size = 8;
//	Board(int size) :size(size) { populate(); };
//	vector<Square*> squares;
//	void populate() 
//	{
//		for (int i = 0; i < size; i++)
//		{
//			for (int k = 0; k < size; k++)
//			{
//				squares.push_back(&Square(i, k));
//			}
//		}
//	}
//	vector<Square*>& operator[](int x)
//	{
//		vector<Square*>::const_iterator first = squares.begin() + (x * size);
//		vector<Square*>::const_iterator last = squares.begin() + x * size + size;
//		vector<Square*> subSquares(first, last);
//		return subSquares;
//	}
//};