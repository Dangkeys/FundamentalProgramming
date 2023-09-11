#include <stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
#define scount 80
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x, screen_y };
COORD characterPos = { 0, 0 };
SMALL_RECT windowSize = { 0, 0, screen_x - 1, screen_y - 1 };
COORD star[scount];
COORD player;
int health = 10;
int shipColor = 200;
int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}
int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
        ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}
void init_star()
{
    for (int i = 0; i < scount; i++)
    {
        star[i].X = rand() % screen_x;
        star[i].Y = rand() % screen_y;
    }
}
void init_player()
{
    player.X = screen_x / 2;
    player.Y = screen_y - 2;
}
void clear_buffer()
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
            consoleBuffer[x + screen_x * y].Attributes = 7;
        }
    }
}
void fill_star_to_buffer()
{
    for (int i = 0; i < scount; i++)
    {
        consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
        consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
    }
}
void drawShipToBuffer(int x, int y)
{
    consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
    consoleBuffer[x + screen_x * y].Attributes = shipColor;
}   
void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
        &windowSize);
}
void star_fall()
{
    int i;
    for (i = 0; i < scount; i++)
    {
        if (star[i].Y >= screen_y - 1)
        {
            star[i].X = rand() % screen_x;
            star[i].Y = 1;
        }
        else
        {
            star[i].Y++;
        }
    }
}
void checkCollision()
{
    for (int i = 0; i < scount; i++)
    {
        if (star[i].X == player.X && star[i].Y == player.Y)
        {
            star[i].X = rand() % screen_x;
            star[i].Y = rand() % screen_y;
            health--;
        }
    }
}
int main()
{
    bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setMode();
    init_star();
    while (play)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0)
        {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true)
                {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
                    {
                        play = false;
                    }
                    if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
                    {
                        shipColor = (rand() % 254) + 1;
                    }
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT)
                {
                    int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                        FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        shipColor = rand() % 255;
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
                    {
                        player.X = posx;
                        player.Y = posy;
                        drawShipToBuffer(posx, posy);
                    }
                }
            }
            delete[] eventBuffer;
        }
        // no input
        star_fall();
        clear_buffer();
        drawShipToBuffer(player.X, player.Y);
        fill_star_to_buffer();
        fill_buffer_to_console();
        Sleep(100);
        checkCollision();
        if (health <= 0)
            play = false;
    }
    return 0;
}