#include<stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
#define scount 80
int X,Y,i,Damage,a;
int posy,posx;
int color=2;
bool play = true;

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
COORD star[scount];
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };

char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = {x,y}; DWORD num_read;
	if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )
		return '\0';
	else
		return buf[0];
}

void ship_buffer()
{

		consoleBuffer[posx-2 + screen_x* posy].Char.AsciiChar = '<' ;
		consoleBuffer[posx-1+ screen_x * posy].Char.AsciiChar = '-' ;
		consoleBuffer[posx+ screen_x * posy].Char.AsciiChar = '0' ;
		consoleBuffer[posx+1+ screen_x * posy].Char.AsciiChar = '-' ;
		consoleBuffer[posx+2+ screen_x * posy].Char.AsciiChar = '>' ;
		consoleBuffer[posx-2+ screen_x * posy].Attributes = color;
		consoleBuffer[posx-1+ screen_x * posy].Attributes = color;
		consoleBuffer[posx+ screen_x * posy].Attributes = color;
		consoleBuffer[posx+1+ screen_x * posy].Attributes = color;
		consoleBuffer[posx+2+ screen_x * posy].Attributes = color;
		
}
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void init_star()
{
	for(i=0;i<80;i++)
    {
        Y=(rand()%25);
        X=(rand()%80);
        consoleBuffer[X + screen_x * Y].Char.AsciiChar = '*';
        consoleBuffer[X + screen_x * Y].Attributes = 7;
        star[i].X=X;
        star[i].Y=Y;
    }
}

void clear_buffer()
{
		for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
		consoleBuffer[x + screen_x * y].Char.AsciiChar = 0 ;
		consoleBuffer[x + screen_x * y].Attributes = 7;
		}
		}
}

void starFall()
{
	
	for(int i=0;i<scount;i++)
            {
            
				if(star[i].Y>=screen_y-1||(star[i].Y==posy-1&&star[i].X==posx-2)||(star[i].Y==posy-1&&star[i].X==posx-1)||(star[i].Y==posy-1&&star[i].X==posx)||(star[i].Y==posy-1&&star[i].X==posx+1)||(star[i].Y==posy-1&&star[i].X==posx+2))
                    {
						star[i]={(rand()%80),0};
					}
				else
                    star[i].Y++;

                consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
                consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
            }


}
void fill_buffer_to_console()
	{
		WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
	}
	int setMode()
	{
		rHnd = GetStdHandle(STD_INPUT_HANDLE);
		fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
		SetConsoleMode(rHnd, fdwMode);
		return 0;
	}
int main()
{	
	setConsole(screen_x, screen_y);
	srand( time( NULL ) );
	init_star();
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	
	setMode();
	while (play)
	{
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) 
		{
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) 
			{
				if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true ) 
				{
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) 
					{
						play = false;
					}
					if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
					{
						srand( time( NULL ) );
						color = (rand()%15)+1;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) 
				{
				posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
				posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
				if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) 
				{
					srand( time( NULL ) );
					color = (rand()%15)+1;
				}
				else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) 
				{
					clear_buffer();
					ship_buffer();
					fill_buffer_to_console();
					
				}
				}
			}delete[] eventBuffer;
		}
				
				if(cursor(posx-2,posy-1)=='*'||cursor(posx-1,posy-1)=='*'||cursor(posx,posy-1)=='*'||cursor(posx+1,posy-1)=='*'||cursor(posx+2,posy-1)=='*')
				{
					Damage++;	
				}
				if(Damage>=10)
					play = false;
				
				clear_buffer();
				ship_buffer();
				starFall();
				fill_buffer_to_console();
		Sleep(80);
	}
	
	return 0;
}






