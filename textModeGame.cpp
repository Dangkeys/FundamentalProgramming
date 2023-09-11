#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoXY(int x, int y);

void eraseShip(int x, int y);

void drawShip(int x, int y);
void eraseBullet(int x, int y);

void drawBullet(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);

void paintColor(int x, int y);

enum Movement
{
    right,
    stop,
    left
};

typedef struct Bullet
{
    bool active;
    int x;
    int y;
} Bullet;
#define MAXBULLET 5
int main()
{
    setcursor(0);
    setcolor(2, 4);

    char input = ' ';
    int x = 2, y = 20;

    // set ship
    Movement shipMovement = stop;

    // set bullet
    int bulletCounter = MAXBULLET;
    Bullet bullet[4];
    for (int i = 0; i < 5; i++)
    {
        bullet[i].active = false;
    }

    drawShip(x, y);
    do
    {
        if (_kbhit())
        {
            input = _getch();
            // inputeck conditions
            if (input == 'a')
            {
                shipMovement = left;
            }
            if (input == 'd')
            {
                shipMovement = right;
            }
            if (input == 's')
            {
                shipMovement = stop;
            }
            if (input == ' ')
            {
                if (bulletCounter > 0)
                {
                    for (int i = 0; i < 5; i++)
                    {
                        if (bullet[i].active == false)
                        {
                            bullet[i].active = true;
                            bullet[i].x = x + 4;
                            bullet[i].y = y - 1;
                            bulletCounter--;
                            break;
                        }
                    }
                }
            }
            fflush(stdin);
        }

        // movement ship
        if (shipMovement == right)
        {
            if (x + 1 != 80)
            {
                paintColor(x, y);
                drawShip(++x, y);
            }
        }
        else if (shipMovement == left)
        {
            if (x - 1 != -1)
            {
                paintColor(x, y);
                drawShip(--x, y);
            }
        }

        // movement bullet
        setcolor(2, 0);
        for (int i = 0; i < 5; i++)
        {
            if (bullet[i].y == 0)
            {
                eraseBullet(bullet[i].x, bullet[i].y);
                bullet[i].active = false;
                bulletCounter++;
            }
            if (bullet[i].active)
            {
                eraseBullet(bullet[i].x, bullet[i].y);
                drawBullet(bullet[i].x, --bullet[i].y);
            }
        }
        setcolor(2, 4);

        Sleep(500);
    } while (input != 'x');
    return 0;
}
void gotoXY(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void eraseShip(int x, int y)
{
    gotoXY(x, y);
    printf("        ");
}

void drawShip(int x, int y)
{
    gotoXY(x, y);
    printf(" <-0-> ");
}

void eraseBullet(int x, int y)
{
    gotoXY(x, y);
    printf(" ");
}

void drawBullet(int x, int y)
{
    gotoXY(x, y);
    printf("^");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;

    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void paintColor(int x, int y)
{
    setcolor(2, 0);
    drawShip(x, y);
    eraseShip(x, y);
    setcolor(2, 4);
}