#include <iostream>
#include<conio.h>
#include <Windows.h>

using namespace std;

bool gameOver;
const int width = 11;
const int height = 15;
int figure;
int score;
int x1 = 200, Y1 = 200, x2 = 200, y2 = 200, y3 = 200, x3 = 200, x4 = 200, y4 = 200;

enum eDirection { STOP = 0, LEFT, RIGHT, DOWN, TURN };
eDirection dir;



void Setup() {
	gameOver = false;
	dir = DOWN;
	score = 0;
	int figure = rand() % 7;

}

void Draw() {
	system("cls");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 or j == width - 1) {
				cout << "#";
			}
			else if (i == Y1 and j == x1 or i == y2 and j == x2 or i == y3 and j == x3 or i == y4 and j == x4) {
				cout << "0";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "SCORE:" << score << endl;


}

void Input() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {
	switch (figure) {
		case 0: // j
			x1 = 6;
			Y1 = 0;
			x2 = 6;
			y2 = 1;
			x3 = 6;
			y3 = 2;
			x4 = 5;
			y4 = 2;
			break;
		case 1: // i
			x1 = 6;
			Y1 = 0;
			x2 = 6;
			y2 = 1;
			x3 = 6;
			y3 = 2;
			x4 = 6;
			y4 = 3;
			break;
		case 2: // o
			x1 = 6;
			Y1 = 0;
			x2 = 5;
			y2 = 0;
			x3 = 6;
			y3 = 1;
			x4 = 5;
			y4 = 1;
			break;
		case 3: // L
			x1 = 6;
			Y1 = 0;
			x2 = 6;
			y2 = 1;
			x3 = 6;
			y3 = 2;
			x4 = 7;
			y4 = 2;
			break;
		case 4: // z
			x1 = 6;
			Y1 = 0;
			x2 = 5;
			y2 = 0;
			x3 = 6;
			y3 = 1;
			x4 = 7;
			y4 = 1;
			break;
		case 5: // t
			x1 = 6;
			Y1 = 0;
			x2 = 6;
			y2 = 1;
			x3 = 5;
			y3 = 1;
			x4 = 7;
			y4 = 1;
			break;
		case 6: // s
			x1 = 6;
			Y1 = 0;
			x2 = 7;
			y2 = 0;
			x3 = 6;
			y3 = 1;
			x4 = 5;
			y4 = 1;

	}
	if (y4 != 14) {
		Y1++;
		y2++;
		y3++;
		y4++;
		switch (dir)
		{
		case LEFT:
			x1--;
			x2--;
			x3--;
			x4--;
			break;
		case RIGHT:
			x1++;
			x2++;
			x3++;
			x4++;
			break;
		case DOWN:
			Y1++;
			y2++;
			y3++;
			y4++;
			break;
		}
	}
	else {
		figure = rand() % 7;
	}
}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Logic();
		Sleep(200);
	}
	if (gameOver) {
		cout << "GAME OVER !!!" << endl << "YOUR SCORE : " << score << endl;
	}
}