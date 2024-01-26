#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <conio.h>
#include <Windows.h>
const int SPEED = 200;
struct snake
{

	int x, y;
	snake(int xx = 0, int yy = 0) :x(xx), y(yy) {}
};
class field
{

	int n, m;
	std::pair<int, int> b;
	std::vector<std::vector<std::string>> matrix;
	snake s;
public:

	field(int nn = 20, int mm = 20) :n(nn), m(mm),s(n/2,m/2)
	{
		matrix.resize(nn+2);
		for (size_t i = 0; i < matrix.size(); i++)
		{
			matrix[i].resize(mm+2," ");
		}
		for (size_t i = 0; i < nn+2; i++)
		{
			matrix[0][i] = "0";
			matrix[i][0] = "0";
			matrix[19][i] = "0";
			matrix[i][19] = "0";
		}
	}
	
	void gen_random_field()
	{
		matrix[s.x][s.y] = "s";
		std::random_device rd;
		std::default_random_engine gen(rd());
		std::uniform_int_distribution<> dist1{1, n - 2}, dist2{1,m - 2 };
		int x = dist1(gen), y = dist2(gen);
		matrix[x][y] = "*";
		b = std::make_pair(x, y);
	}
	void new_b()//создает новую €годку после столкновени€ со змейкой
	{
		if (s.x == b.first && s.y == b.second)
		{
			matrix[b.first][b.second] = " ";
			gen_random_field();
		}
	}
	void update()
	{
			char a;
			int ch;
			bool k = true;
			while (k)
			{
				a = _getch();
				ch = static_cast<int>(a);
				switch (ch)
				{
				case -32:
					break;
				case 75:  // влево
					//std::cout << "l";
					while (!_kbhit())
					{
						matrix[s.x][s.y] = " ";
							
						if (s.y == 1)
							throw std::out_of_range("You died");
						else
							--s.y;

						matrix[s.x][s.y] = "s";
						new_b();
						Sleep(SPEED);
						system("cls");
						print();
					}
					break;
				case 77: // вправо

					//std::cout << "r";
					while (!_kbhit())
					{
						matrix[s.x][s.y] = " ";
						if (s.y == n-2)
							throw std::out_of_range("You died");
						else
							++s.y;
						matrix[s.x][s.y] = "s";
						new_b();
						Sleep(SPEED);
						system("cls");
						print();
					}
					break;
				case 80: // вниз

					//std::cout << "d";
					while (!_kbhit())
					{
						matrix[s.x][s.y] = " ";
						if (s.x == n-2)
							throw std::out_of_range("You died");
						else
							++s.x;
						matrix[s.x][s.y] = "s";
						new_b();
						Sleep(SPEED);
						system("cls");
						print();
					}
					break;
				case 72: // вверх

					//std::cout << "u";
					while (!_kbhit())
					{
						matrix[s.x][s.y] = " ";
						if (s.x ==  1)
							throw std::out_of_range("You died");
						else
							--s.x;
						matrix[s.x][s.y] = "s";
						new_b();
						Sleep(SPEED);
						system("cls");
						print();
					}
					break;
				default:
					std::cout << "i am stupid" << std::endl;
				}



			
		}
		
		
		
		
		
	}

	void print()
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				std::cout << matrix[i][j]<<" ";
			}
			std::cout << "\n";
		}

	}

};
