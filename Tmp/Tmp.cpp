// Tmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <vector>

using namespace std;

size_t GetReverse(size_t number)
{
	size_t reverse = 0;
	if (number % 10 == 0) { return 0; }
	for (; number != 0;)
	{
		reverse = reverse * 10;
		reverse = reverse + number % 10;
		number = number / 10;
	}
	return reverse;
}

bool IsTotallyUneven(size_t number)
{
	size_t reverse = 0;
	for (; number != 0;)
	{
		reverse = number % 10;
		if (reverse % 2 == 0) { return false;  }
		number = number / 10;
	}
	return true;
}

size_t Vraag1()
{
	size_t Count = 0;
	for (size_t i = 0; i < 100000000; i++)
	{
		size_t r = GetReverse(i);
		if (r == 0) { continue; }
		if (!IsTotallyUneven(r + i)) { continue; }
		Count++;
		_tprintf(L"%Iu\r\n", i);
	}
	_tprintf(L"count: %Iu\r\n", Count);
	return Count;
}

size_t GetNumbersTogetter(size_t number)
{
	size_t Total = 0;
	for (; number != 0;)
	{
		Total += number % 10;
		number = number / 10;
	}
	return Total;
}

vector <size_t>  GetFibonacciRange(size_t Max)
{
	size_t last = 0;
	vector <size_t> Range;
	Range.push_back(0);
	for (size_t i = 1; i < Max;)
	{
		size_t n = i + last;
		Range.push_back(n);
		last = i;
		i = n;
	}
	return Range;
}

size_t Vraag2()
{
	size_t last = 0;
	vector <size_t> Bingos;
	vector <size_t> Range = GetFibonacciRange(1000000000000000000);
	for (auto it = Range.begin(); it != Range.end(); ++it)
	{
		size_t n = (*it) + last;
		last = *it;
		double sq = sqrt(GetNumbersTogetter(*it));
		double whole;

		if (modf(sq, &whole) == 0)
		{
			_tprintf(L"Found one: %Iu\r\n", *it);
			Bingos.push_back(*it);
		}
		
	}
	return Bingos.size();
}

typedef double Coord[3];

Coord &Vraag3()
{
	Coord Start = {30.0, 50.0, 90.0};
	//Coord Prog = { 0.0000075, -0,000000125, 0.1 }
	//Coord Prog ={ 133333.33333333333333333333333333, -8000000, 10};
	Coord Prog ={0.01666666666666666666666666666667, 1, 0.00000125};
	for (int i = 0; i < 1500; ++i)
	{
		double Points = 20.0;
		bool StillGoing = false;
		do{
			StillGoing = false;
			for (int c = 0; c < 3; c++)
			{
				Points-=Prog[c];
				if (Points <= 0) {
					Points+=Prog[c];
					continue;
				}
				StillGoing = true;
				//_tprintf(L"moving %ld: with %.3f points, left is %.2f\r\n", c, Prog[c], Points);
				if (c == 0) { Start[c]+=Prog[c]; }
				else {
					Start[c]-=Prog[c];
				}
			}
		} while (StillGoing);
		_tprintf(L"New Pos {x: %.3f, y: %.3f, z: %.3f }\r\n", Start[0], Start[1], Start[2]);
	}
	return Start;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//vraag 1
	//_tprintf(L"vraag1: %Iu\r\n", Vraag1());

	//_tprintf(L"vraag2: %Iu\r\n", Vraag2());

	Coord &EndPos = Vraag3();
	_tprintf(L"vraag 3: { x: %.2f, y: %.2f, z: %.2f }\r\n", EndPos[0], EndPos[1], EndPos[2]);

	getchar();


	return 0;
}

