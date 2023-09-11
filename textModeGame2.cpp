#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

char cursor(int x, int y);
void gotoXY(int x, int y);
void drawShip(int x, int y);
void drawBullet(int x, int y);
void clear(int x, int y);
void drawStar();
void drawScore(int score);
int main()
{
	//random
	srand(time(NULL));
	for (int i = 0; i < 20; ++i) {
		drawStar();
	}

	//score
	int score = 0;

	//logic
	char input = '.';
	int x = 38, y = 20;
	int bulletX, bulletY, i;
	int bullet = 0;
	drawShip(x, y);
	do {
		if (_kbhit()) {
			input = _getch();
			if (input == 'a') { drawShip(--x, y); }
			if (input == 'd') { drawShip(++x, y); }      
			if (bullet != 1 && input == ' ') { bullet = 1; bulletX = x + 3; bulletY = y - 1; }
			fflush(stdin);
		}
		if (bullet == 1) {
			clear(bulletX, bulletY);
			if (bulletY == 2) { bullet = 0; }
			else {
				if (cursor(bulletX, bulletY - 1) == '*') {
					Beep(1000, 500);
					clear(bulletX, bulletY - 1);
					score++;
					drawStar();
				}
				drawBullet(bulletX, --bulletY);
			}
		}
		drawScore(score);
		Sleep(100);
	} while (input != 'x');
	return 0;
}

char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}
void gotoXY(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void drawShip(int x, int y)
{
	gotoXY(x, y); printf(" <-0-> ");
}
void drawBullet(int x, int y)
{
	gotoXY(x, y); printf("^");
}
void clear(int x, int y)
{
	gotoXY(x, y); printf(" ");
}
void drawStar()
{
	int x = rand() % 61 + 10;
	int y = rand() % 4 + 2;
	gotoXY(x, y); printf("*");
}
void drawScore(int score)
{
	gotoXY(68, 1); printf("%d", score);
}