#include <cstdlib>
#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

const int Height = 25;
const int Width = 19;
void F_Map(char matrix[Height][Width]) {
	for (int i = 1; i < Height - 1; i++) {
		for (int j = 1; j < Width - 1; j++) {
			matrix[i][j] = ' ';
		}
	}
	for (int i = 0; i < Height; i++) {
		matrix[i][0] = '*';
	}
	for (int i = 0; i < Height; i++) {
		matrix[i][Width - 1] = '*';
	}
	for (int j = 1; j < Width - 1; j++) {
		matrix[0][j] = '*';
	}
	for (int j = 1; j < Width - 1; j++) {
		matrix[Height - 1][j] = '*';
	}
	
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			std::cout << matrix[i][j] <<" ";
		}
		std::cout << std::endl ;
	}
}
void F_Snake(char matrix[Height][Width]) {
	for (int i = 1; i < Height - 1; i++) {
		for (int j = 1; j < Width - 1; j++) {
			if (matrix[i][j] != 'O') {
				matrix[i][j] = ' ';
			}
		}
	}
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			std::cout << matrix[i][j]<<" ";
		}
		std::cout << std::endl;
	}
}
bool F_Move(int snake[Height*Width][2],int step) {
	
	if (step==1) {
		if (snake[0][1] == 0) {
			return false;
		}
		for (int i = Height * Width-1; i > 0; i--) {
			if (snake[i][0] != -1) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
		}
		snake[0][0] = snake[1][0];
		snake[0][1] = snake[1][1] - 1; 
	}
	if (step==2) {
		if (snake[0][1] == Width-1) {
			return false;
		}
		for (int i = Height * Width-1; i > 0; i--) {
			if (snake[i][0] != -1) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
		}
		snake[0][0] = snake[1][0];
		snake[0][1] = snake[1][1] +1;
	}
	if (step==3) {
		if (snake[0][0] == 0) {
			return false;
		}
		for (int i = Height * Width-1; i > 0; i--) {
			if (snake[i][0] != -1) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
		}
		snake[0][0] = snake[1][0]-1;
		snake[0][1] = snake[1][1];
	}
	if (step==4){
		if (snake[0][0] == Height-1) {
			return false;
		}
		for (int i = Height * Width-1; i > 0; i--) {
			if (snake[i][0] != -1) {
				snake[i][0] = snake[i - 1][0];
				snake[i][1] = snake[i - 1][1];
			}
		}
		snake[0][0] = snake[1][0]+1;
		snake[0][1] = snake[1][1];
	}
	return true;
}
void F_Snake2(char matrix[Height][Width], int snake[Height*Width][2])
{
	for (int i = 0; i < Height*Width; i++) {
		if (snake[i][0] == -1) {
			break;
		}
		for (int j = 0; j < 2; j++) {
			matrix[snake[i][0]][snake[i][1]] = 'O';
		}
	}
}


int main()
{
	//setlocale(LC_ALL, "");
	system("mode con cols=43 lines=32");
	system("Color 09");
	char matrix[Height][Width];
	std::cout << "GAME PURPOSE:"<<std::endl<< "COMPLETE THE FIELD WITH CIRCLES, "<<std::endl<<"WITHOUT LEAVING THE BORDERS"<<std::endl;
	system("pause");
	bool End_of_game=false;
	F_Map(matrix);
	//system("pause");
	system("cls");
	
	
	int snake[Height*Width][2];
	for (int i = 0; i < Height*Width; i++) {
		for (int j = 0; j < 2; j++) {
			snake[i][j] =-1 ;
		}
	}
	
	snake[0][0] = 10;
	snake[0][1] = 9;
	snake[1][0] = 10;
	snake[1][1] = 10; 
	snake[2][0] = 10;
	snake[2][1] = 11;

	F_Snake2(matrix, snake);//ставит z там, где элементы матрицы snake не равны -1
	F_Snake(matrix);//печатает поле и новую змейку
	int step=1;//нажимает кнопку "влево"
		int Time = 0;
		int c;
		Sleep(1000);
		while (true) {
			if (_kbhit()) {
				
				c = _getch();//возвращает истину, если нажата какая-то кнопка
				Sleep(50);
				switch (c) {
				case 'a': step = 1;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 75: step = 1;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 'd': step = 2;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 77: step = 2;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 'w': step = 3;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 72: step = 3;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 's': step = 4;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				case 80: step = 4;
					if (!F_Move(snake, step)) {
						End_of_game = true;
					}; break;
				default: if (!F_Move(snake, step)) {
					End_of_game = true;
				};
				}
			}
			else if (!F_Move(snake, step)) {
				End_of_game = true;
			};
			Time += 10;
			system("cls");
			F_Snake2(matrix, snake);
			F_Snake(matrix);
			if (End_of_game) {
				break;
			}
			}
		std::cout << "GAME OVER";
		Sleep(100);
	
	return 0;
}

