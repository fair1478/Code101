#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define screen_x 80
#define screen_y 25
int i,j,s=0,g[1000],Score=-1;

COORD characterPos = { 0,0 };
CHAR_INFO consoleBuffer[screen_x * screen_y];
HANDLE wHnd;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };

void setcolor(int fg,int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void clear_buffer()
	{
		for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
		consoleBuffer[x + screen_x * y].Char.AsciiChar = 0 ;
		consoleBuffer[x + screen_x * y].Attributes = 7;
		}
		}
		setcolor(2,7);	
	}
void fill_buffer_to_console()
	{
		WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
	}

void fill_data_to_buffer()
	{
		for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
		consoleBuffer[x + screen_x * y].Char.AsciiChar = 0;
		consoleBuffer[x + screen_x * y].Attributes = 0;
		}
		}
	}
int setConsole(int x, int y)
	{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
	}

void score(int x,int y)
{
	COORD t = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , t);
	printf("%d",++Score);
}
char cursor(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = {x,y}; DWORD num_read;
	if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )
		return '\0';
	else
		return buf[0];
}

void draw_star(int o, int p)
{
	COORD t = { o, p };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , t);
	printf("*");
}


void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&lpCursor);
}

void erase_bullet(int o, int p)
{
	COORD t = { o, p };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , t);
	printf("%c",s);
}
void draw_bullet(int o, int p)
{
	COORD t = { o, p };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , t);
	printf("8");
}
void draw_ship(int x, int y)
{
	COORD c = { x, y };
	setcolor(2,7);
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf("<-0->");
	setcolor(2,0);
}
void erase_ship(int x,int y)
{
	
	COORD c = { x, y };
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE) , c);
	printf("%c%c%c%c%c",s,s,s,s,s);	
}
int main()
{
	setConsole(screen_x, screen_y);
	
	int x=50,y=20,h=0,Bx[100],By[100];
	char ch=' ';
	setcursor(0);
	setcolor(2,0);
	score(79,1);
	fill_data_to_buffer();
	fill_buffer_to_console();
	Sleep(500);
	clear_buffer();
	int Y=(rand()%4)+1;
	int X=(rand()%61)+9;
	
	draw_ship(x,y);
	do {
		if (_kbhit())
		{
			ch=_getch();
			if(ch=='a') 
				h=1;
			else if(ch=='d') 
				h=2;
			else if(ch=='s') 
				h=0;
			if(ch==' ')
				for(int n=0;n<1000;n++)
					if(g[n]==0)
					{
						g[n]=1;
						Bx[n]=x+2;
						By[n]=y-1;
						break;
					}
		fflush(stdin);
		}
		srand( time( NULL ) );
		draw_star(X,Y);
		if(h==2&&x+1<=73)
		{
			erase_ship(x,y);
			draw_ship(++x,y);
		}
		else if(h==1&&x-1>=0)
		{
			erase_ship(x,y);
			draw_ship(--x,y);
		}
		
		
		for(int n=0;n<1000;n++)
			if(g[n])
			{
				erase_bullet(Bx[n],By[n]);
				if(By[n]>0)
					{
						erase_bullet(Bx[n],By[n]);
						if((cursor(Bx[n],By[n]-1))!='*')
							{
								draw_bullet(Bx[n],--By[n]);
							}
						else 
							{
								erase_bullet(Bx[n],By[n]);
								erase_bullet(Bx[n],--By[n]);
								g[n]=0;
								Y=(rand()%4)+2;
								X=(rand()%61)+10;
								draw_star(X,Y);
								Beep(500,150);
								score(79,1);
							}
					}
				else
				{
					g[n]=0;
				}
			}
	Sleep(50);
	} 	
	while (ch!='x');
	return 0;

}
