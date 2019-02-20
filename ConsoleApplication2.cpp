#include "pch.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <stdlib.h>


using namespace std;

const int N = 4;
int game_place[N][N];

void InitGameplace(); // Заполняем массив
void ShowGamePlace(); // Вывод игрового поля
void MixGamePlace();	// Перемешать игровое поле
void GamePlay();
bool GameWin(); // 

int main()
{
	setlocale(LC_ALL, "ru");

	InitGameplace();

	ShowGamePlace(); 

	MixGamePlace();

	ShowGamePlace();
	while (GameWin) {
		GamePlay();
		system("cls");
		ShowGamePlace();
	}

	
}

void InitGameplace() {
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			game_place[i][j] = k; // Заполняем массив числами от 0 до 15
			k++;
		}
	}
}

void MixGamePlace() {
	srand(time(NULL));
	int x1, y1, x2, y2, temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { // Перемешиваем числа в массиве
			x1 = rand() % 3;
			y1 = rand() % 3;
			x2 = rand() % 3;
			y2 = rand() % 3;
			temp = game_place[x1][y1];
			game_place[x1][y1] = game_place[x2][y2];
			game_place[x2][y2] = temp;
		}
	}
}

void ShowGamePlace() {
	cout << endl;
	cout << "***" << endl;
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << game_place[i][j] << " | ";
		}
		cout << endl;
	}
}


bool GameWin() {
	int game_win[N][N]{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0} }; //Сравниваем с эталоном
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (game_place[i][j] == game_win[i][j]) {
				k++;
			}
		}
	}

	if (k == 16) {
		return true;
	}
	else {
		return false;
	}
}


void GamePlay(){
	/*setlocale(0, "rus");
	char symbol = _getch();

	while ((symbol = _getch())) {
		switch (symbol) {
		case 72:
			std::cout << "Вверх\n";
			break;
		case 75:
			std::cout << "Влево\n";
			break;
		case 77:
			std::cout << "Вправо\n";
			break;
		case 80:
			std::cout << "Вниз\n";
			break;
		default:
			break;
		}
	}*/

	setlocale(0, "rus");
	char symbol = _getch();
	cout << "Enter said" << endl;

	switch (symbol) {
		case char(72): { // вверх
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (game_place[i][j] == 0 && i > 0) {
						swap(game_place[i][j], game_place[i - 1][j]);
						i = N - 1;
						j = N - 1;
					}
				}
			}
			break;
		}
		case char(77) : { // вправо
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (game_place[i][j] == 0 && j < N - 1) {
						swap(game_place[i][j], game_place[i][j + 1]);
						i = N - 1;
						j = N - 1;
					}
				}
			}
			break;
		}
		case char(75) : { // влево
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (game_place[i][j] == 0 && j < N - 1) {
						swap(game_place[i][j], game_place[i][j - 1]);
						i = N - 1;
						j = N - 1;
					}
				}
			}
			break;
		}
		case char(80) : { // вниз
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (game_place[i][j] == 0 && i < N - 1) {
						swap(game_place[i][j], game_place[i + 1][j]);
						i = N - 1;
						j = N - 1;
					}
				}
			}
			break;
		}
		default: {
			cout << "Ne to";
		}
	}
		
}